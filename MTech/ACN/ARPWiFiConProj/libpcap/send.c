// http://yuba.stanford.edu/~casado/pcap/section4.html

#include <arpa/inet.h>
#include <net/ethernet.h>
#include <netinet/ether.h>
#include <netinet/if_ether.h>
#include <netinet/in.h>
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>

u_int16_t handle_ethernet(u_char *args, const struct pcap_pkthdr *pkthdr,
                          const u_char *packet) {
  struct ether_header *eptr;

  eptr = (struct ether_header *)packet;

  fprintf(stdout, "ethernet header source: %s",
          ether_ntoa((const struct ether_addr *)&eptr->ether_shost));
  fprintf(stdout, " destination: %s ",
          ether_ntoa((const struct ether_addr *)&eptr->ether_dhost));

  if (ntohs(eptr->ether_type) == ETHERTYPE_IP) {
    fprintf(stdout, "(IP)");
  } else if (ntohs(eptr->ether_type) == ETHERTYPE_ARP) {
    fprintf(stdout, "(ARP)");
  } else if (ntohs(eptr->ether_type) == ETHERTYPE_REVARP) {
    fprintf(stdout, "(RARP)");
  } else {
    fprintf(stdout, "(?)");
    exit(1);
  }
  fprintf(stdout, "\n");

  return eptr->ether_type;
}

void my_callback(u_char *args, const struct pcap_pkthdr *pkthdr,
                 const u_char *packet) {
  u_int16_t type = handle_ethernet(args, pkthdr, packet);

  if (type == ETHERTYPE_IP) {            /* handle IP packet */
  } else if (type == ETHERTYPE_ARP) {    /* handle arp packet */
  } else if (type == ETHERTYPE_REVARP) { /* handle reverse arp packet */
  }
}

int main(int argc, char **argv) {
  char *dev;
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *descr;
  struct bpf_program fp; /* hold compiled program     */
  bpf_u_int32 maskp;     /* subnet mask               */
  bpf_u_int32 netp;      /* ip                        */
  u_char *args = NULL;

  if (argc < 2) {
    fprintf(stdout, "Usage: %s numpackets \"options\"\n", argv[0]);
    return 0;
  }

  dev = pcap_lookupdev(errbuf);
  if (dev == NULL) {
    printf("%s\n", errbuf);
    exit(1);
  }

  // ask pcap for the network address and mask of the device
  pcap_lookupnet(dev, &netp, &maskp, errbuf);

  // open device for reading. NOTE: defaulting to promiscuous mode
  descr = pcap_open_live(dev, BUFSIZ, 1, -1, errbuf);
  if (descr == NULL) {
    printf("pcap_open_live(): %s\n", errbuf);
    exit(1);
  }

  if (argc > 2) {
    // Lets try and compile the program. non-optimized
    if (pcap_compile(descr, &fp, argv[2], 0, netp) == -1) {
      fprintf(stderr, "Error calling pcap_compile\n");
      exit(1);
    }

    // set the compiled program as the filter
    if (pcap_setfilter(descr, &fp) == -1) {
      fprintf(stderr, "Error setting filter\n");
      exit(1);
    }
  }

  // and loop
  pcap_loop(descr, atoi(argv[1]), my_callback, args);

  fprintf(stdout, "\nbye!\n");

  return 0;
}
