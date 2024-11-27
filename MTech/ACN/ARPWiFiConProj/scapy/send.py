from scapy.all import ARP, Ether, sendp
from scapy.arch import get_if_hwaddr, get_if_addr
from scapy.packet import Padding

import constants


def send_request(target_ip, interface="wlo1"):
    kv_data = {constants.req_key: "True", constants.adm_no_key: "24M186"}

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
    # target_ip = "192.168.1.1"

    iface = "wlo1"
    target = get_if_addr(iface)

    send_request(target_ip=target, interface=iface)
