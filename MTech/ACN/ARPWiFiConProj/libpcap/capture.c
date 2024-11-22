/* Simple ARP Sniffer.                                                   */
/* Author: Luis Martin Garcia. luis.martingarcia [.at.] gmail [d0t] com  */
/* To compile: gcc arpsniffer.c -o arpsniff -lpcap                       */
/* Run as root!                                                          */
/*                                                                       */
/* https://github.com/lsanotes/libpcap-tutorial/blob/master/arpsniffer.c */
/*                                                                       */
/* This code is distributed under the GPL License. For more info check:  */
/* http://www.gnu.org/copyleft/gpl.html                                  */

#include <linux/if_link.h>
#include <net/if.h>
#include <pcap.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/fcntl.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <unistd.h>

#define ARP_REQUEST 1
#define ARP_REPLY 2

#define MAXBYTES2CAPTURE 2048

// ARP Header (assuming Ethernet+IPv4)
typedef struct arphdr {
  u_int16_t hType;
  u_int16_t pType;
  u_char hAddrLen;
  u_char pAddrLen;
  u_int16_t operCode;
  u_char senderHWAddr[6];
  u_char senderIPAddr[4];
  u_char targetHWAddr[6];
  u_char targetIPAddr[4];
} arphdr_t;

void getMacAddress(u_char *result, char *nic) {
  struct ifreq s;
  int fd = socket(PF_INET, SOCK_DGRAM, IPPROTO_IP);

  strcpy(s.ifr_name, nic);

  if (0 == ioctl(fd, SIOCGIFHWADDR, &s)) {
    for (int i = 0; i < 6; ++i) {
      result[i] = (unsigned char)s.ifr_addr.sa_data[i];
    }
  }
}

int main(int argc, char *argv[]) {

  int i = 0;

  bpf_u_int32 netAddr = 0, netMask = 0;
  struct bpf_program filter;
  char errBuf[PCAP_ERRBUF_SIZE];
  pcap_t *NIChandler = NULL;
  struct pcap_pkthdr packetInfo;
  const unsigned char *packet = NULL;
  arphdr_t *ARPHeader = NULL;

  memset(errBuf, 0, PCAP_ERRBUF_SIZE);

  if (argc != 2) {
    printf("USAGE: arpsniffer <interface>\n");
    exit(1);
  }

  u_char macAddress[6];
  getMacAddress(macAddress, argv[1]);

  // Open network device for packet capture
  if ((NIChandler =
           pcap_open_live(argv[1], MAXBYTES2CAPTURE, 0, 512, errBuf)) == NULL) {
    fprintf(stderr, "ERROR: %s\n", errBuf);
    exit(1);
  }

  // Look up info from the capture device
  if (pcap_lookupnet(argv[1], &netAddr, &netMask, errBuf) == -1) {
    fprintf(stderr, "ERROR: %s\n", errBuf);
    exit(1);
  }

  // Compiles the filter expression into a BPF filter program
  if (pcap_compile(NIChandler, &filter, "arp", 1, netMask) == -1) {
    fprintf(stderr, "ERROR: %s\n", pcap_geterr(NIChandler));
    exit(1);
  }

  // Load the filter program into the packet capture device
  if (pcap_setfilter(NIChandler, &filter) == -1) {
    fprintf(stderr, "ERROR: %s\n", pcap_geterr(NIChandler));
    exit(1);
  }

  while (true) {

    if ((packet = pcap_next(NIChandler, &packetInfo)) == NULL) {
      fprintf(stderr, "ERROR: Error getting the packet: %s.\n", errBuf);
      exit(1);
    }

    ARPHeader = (struct arphdr *)(packet + 14); /* Point to the ARP header */

    // if ((ntohs(ARPHeader->operCode) == ARP_REQUEST))
    //   continue;

    printf("\n\nReceived Packet Size: %d bytes\n", packetInfo.len);
    printf("Hardware type: %s\n",
           (ntohs(ARPHeader->hType) == 1) ? "Ethernet" : "Unknown");
    printf("Protocol type: %s\n",
           (ntohs(ARPHeader->pType) == 0x0800) ? "IPv4" : "Unknown");
    printf("Operation: %s\n", (ntohs(ARPHeader->operCode) == ARP_REQUEST)
                                  ? "ARP Request"
                                  : "ARP Reply");

    // strcmp(ARPHeader->targetHWAddr, macAddress)

    bool isSolicitedReply = true; // target mac address = my mac address

    for (i = 0; i < 6; i++) {
      if (ARPHeader->targetHWAddr[i] != macAddress[i]) {
        isSolicitedReply = false;
        break;
      }
    }

    if (isSolicitedReply) {
      printf("\nskipping solicited reply\n");
      continue;
    }

    bool isBroadcast = true; // 00:00:00:00:00:00 and FF:FF:FF:FF:FF:FF
    for (i = 0; i < 6; i++) {
      if (ARPHeader->targetHWAddr[i] != 0) {
        isBroadcast = false;
        break;
      }
    }

    // for (i = 0; i < 6; i++) {
    //   if (ARPHeader->targetHWAddr[i] != 255) {
    //     isBroadcast = false;
    //     break;
    //   }
    // }

    printf("\n%b\n", isBroadcast);
    for (i = 0; i < 6; i++)
      printf("%02X:", ARPHeader->targetHWAddr[i]);

    if (isBroadcast) {
      printf("\nskipping router broadcast\n");
      continue;
    }

    // if (ARPHeader->targetHWAddr[i] != 255) {
    //   isSolicitedReply = false;
    //   break;
    // }

    // If is Ethernet and IPv4, print packet contents
    if (ntohs(ARPHeader->hType) == 1 && ntohs(ARPHeader->pType) == 0x0800) {
      printf("Sender MAC: ");

      for (i = 0; i < 6; i++)
        printf("%02X:", ARPHeader->senderHWAddr[i]);

      printf("\nSender IP: ");

      for (i = 0; i < 4; i++)
        printf("%d.", ARPHeader->senderIPAddr[i]);

      printf("\nTarget MAC: ");

      for (i = 0; i < 6; i++)
        printf("%02X:", ARPHeader->targetHWAddr[i]);

      printf("\nTarget IP: ");

      for (i = 0; i < 4; i++)
        printf("%d.", ARPHeader->targetIPAddr[i]);

      printf("\n");
    }

    // break;
  }

  return 0;
}
