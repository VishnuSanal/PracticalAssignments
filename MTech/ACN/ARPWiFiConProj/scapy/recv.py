from scapy.all import sniff, ARP
from scapy.packet import Padding

import constants


def send_email(admission_number, target_mac):
    print(f"Sending confirmation email to {admission_number} for the device {target_mac}")

    # email_utils.send_approval_link(admission_number, target_mac)

    print("debug: limited access")


def process_arp_packet(packet):
    # print(packet.show())

    # if packet.haslayer(ARP):
    if packet.haslayer(ARP) and packet[ARP].op == 2:
        if packet.haslayer(Padding):
            raw_data = packet[Padding].load
            try:
                kv_pairs = dict(item.split("=") for item in raw_data.decode().split("&"))
                if constants.key_request in kv_pairs.keys():
                    admission_number = kv_pairs.get(constants.key_adm_no_extra)
                    target_mac = packet[ARP].hwsrc
                    send_email(admission_number, target_mac)
            except Exception as ignored:
                pass


def arp_sniffer(interface):
    sniff(iface=interface, filter="arp", prn=process_arp_packet, store=0)


if __name__ == "__main__":
    arp_sniffer(interface="wlo1")
