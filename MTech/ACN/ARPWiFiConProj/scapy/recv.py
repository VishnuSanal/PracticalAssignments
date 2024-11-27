from scapy.all import sniff, ARP
from scapy.packet import Padding

import constants


def process_arp_packet(packet):
    # print(packet.show())

    # if packet.haslayer(ARP) and packet[ARP].op == 2:
    if packet.haslayer(ARP):
        if packet.haslayer(Padding):
            raw_data = packet[Padding].load
            try:
                kv_pairs = dict(item.split("=") for item in raw_data.decode().split("&"))
                if constants.req_key in kv_pairs.keys():
                    print(f"Add {packet[ARP].hwsrc} to whitelist (linked to {kv_pairs.get(constants.adm_no_key)})")
            except Exception as ignored:
                pass


def arp_sniffer(interface):
    sniff(iface=interface, filter="arp", prn=process_arp_packet, store=0)


if __name__ == "__main__":
    arp_sniffer(interface="wlo1")
