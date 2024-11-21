from scapy.all import sniff

def process_packet(packet):
    print(packet)

sniff(filter="arp", prn=process_packet)
