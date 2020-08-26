#ifndef CPPINET_DEFINES_HPP
#define CPPINET_DEFINES_HPP

#include <netinet/in.h>

namespace KonstantIMP {

enum SOCKET_FAMILY {
    IB_SOCKET         = AF_IB,
    ALG_SOCKET        = AF_ALG,
    ASH_SOCKET        = AF_ASH,
    CAN_SOCKET        = AF_CAN,
    IPX_SOCKET        = AF_IPX,
    KCM_SOCKET        = AF_KCM,
    KEY_SOCKET        = AF_KEY,
    LCC_SOCKET        = AF_LLC,
    MAX_SOCKET        = AF_MAX,
    NFC_SOCKET        = AF_NFC,
    RDS_SOCKET        = AF_RDS,
    SMC_SOCKET        = AF_SMC,
    SNA_SOCKET        = AF_SNA,
    X25_SOCKET        = AF_X25,
    XDP_SOCKET        = AF_XDP,
    AX25_SOCKET       = AF_AX25,
    CAIF_SOCKET       = AF_CAIF,
    FILE_SOCKET       = AF_FILE,
    INET_SOCKET       = AF_INET,
    IPV4_SOCKET       = AF_INET,
    IRDA_SOCKET       = AF_IRDA,
    ISDN_SOCKET       = AF_ISDN,
    IUCV_SOCKET       = AF_IUCV,
    MPLS_SOCKET       = AF_MPLS,
    ROSE_SOCKET       = AF_ROSE,
    TIPC_SOCKET       = AF_TIPC,
    UNIX_SOCKET       = AF_UNIX,
    INET6_SOCKET      = AF_INET6,
    IPV6_SOCKET       = AF_INET6,
    LOCAL_SOCKET      = AF_LOCAL,
    PPPOX_SOCKET      = AF_PPPOX,
    ROUTE_SOCKET      = AF_ROUTE,
    RXRPC_SOCKET      = AF_RXRPC,
    VSOCK_SOCKET      = AF_VSOCK,
    ATMPVC_SOCKET     = AF_ATMPVC,
    ATMSVC_SOCKET     = AF_ATMSVC,
    BRIDGE_SOCKET     = AF_BRIDGE,
    DECnet_SOCKET     = AF_DECnet,
    ECONET_SOCKET     = AF_ECONET,
    NETROM_SOCKET     = AF_NETROM,
    PACKET_SOCKET     = AF_PACKET,
    PHONET_SOCKET     = AF_PHONET,
    UNSPEC_SOCKET     = AF_UNSPEC,
    NETBEUI_SOCKET    = AF_NETBEUI,
    NETLINK_SOCKET    = AF_NETLINK,
    QIPCRTR_SOCKET    = AF_QIPCRTR,
    WANPIPE_SOCKET    = AF_WANPIPE,
    SECURITY_SOCKET   = AF_SECURITY,
    APPLETALK_SOCKET  = AF_APPLETALK,
    BLUETOOTH_SOCKET  = AF_BLUETOOTH,
    IEEE802154_SOCKET = AF_IEEE802154
};

enum SOCKET_TYPE {
    RAW_SOCKET       = SOCK_RAW,
    RDM_SOCKET       = SOCK_RDM,
    DCCP_SOCKET      = SOCK_DCCP,
    DGRAM_SOCKET     = SOCK_DGRAM,
    PACKETT_SOCKET   = SOCK_PACKET,
    STREAM_SOCKET    = SOCK_STREAM,
    CLOEXEC_SOCKET   = SOCK_CLOEXEC,
    NONBLOCK_SOCKET  = SOCK_NONBLOCK,
    SEQPACKET_SOCKET = SOCK_SEQPACKET
};

}

#endif // CPPINET_DEFINES_HPP