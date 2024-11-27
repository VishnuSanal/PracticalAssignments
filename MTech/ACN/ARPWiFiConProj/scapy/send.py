import socket

from scapy.all import ARP, Ether, sendp
from scapy.arch import get_if_hwaddr, get_if_addr
from scapy.packet import Padding

import constants


def send_request(admission_number, interface="wlo1"):
    # target_ip = "192.168.1.1"
    target_ip = get_if_addr(interface)  # FIXME:

    kv_data = {constants.key_request: "True", constants.key_adm_no_extra: admission_number}

    extra_data = "&".join(f"{key}={value}" for key, value in kv_data.items()).encode()

    arp_reply = (
            Ether(dst="ff:ff:ff:ff:ff:ff", src=get_if_hwaddr(interface)) /
            ARP(op=2, psrc=get_if_addr(interface), hwsrc=get_if_hwaddr(interface), pdst=target_ip,
                hwdst="00:00:00:00:00:00") /
            Padding(load=extra_data)
    )

    # print(f"Request sent")

    sendp(arp_reply, iface=interface, verbose=1)


if __name__ == "__main__":
    # iface = "wlo1"
    # admn_no = input("Enter your admission number: ")
    #
    # send_request(admn_no, iface)

    print(socket.if_nameindex())
