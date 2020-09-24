#ifndef CPPINET_DEFINES_HPP
#define CPPINET_DEFINES_HPP

/**
 * @file cppinet_defines.hpp
 * @author KonstantIMP
 */

#ifdef    __linux

#include <netinet/in.h>
#include <sys/socket.h>

#elif  // __linux

#endif // __linux

#include <cstdint>

namespace KonstantIMP {
    /**
     * @brief This class describes a host information.
     *
     * Used to simple work with host data (addresses, connection type and more) 
     */
    class host_info;

    /**
     * @brief This class describes an internet address.
     *
     * It is an abstract class, because it must be other for every connection type
     */
    class address;

    /**
     * @brief This class describes a socket abstraction.
     *
     * It uses system socket API to open, close, read and write sockets.
     */
    class u_socket;
    
    /**
     * @brief This class describes am intenet port.
     *
     * Need to be used for smart translate port from NETWORK to HOST LONG(SHORT) and back
     */
    class port;

    /**
     * @brief This class dns class.
     *
     * Make requests to DomenNameSystem
     */
    class dns;

    #ifdef    __linux

    /**
     * @brief Socket types enumeration
     */
    enum SOCKET_TYPE : std::uint32_t {
        RAW_SOCKET       = SOCK_RAW,        ///>
        RDM_SOCKET       = SOCK_RDM,        ///>
        DCCP_SOCKET      = SOCK_DCCP,       ///>
        DGRAM_SOCKET     = SOCK_DGRAM,      ///>  
        PACKETT_SOCKET   = SOCK_PACKET,     ///>
        STREAM_SOCKET    = SOCK_STREAM,     ///>
        CLOEXEC_SOCKET   = SOCK_CLOEXEC,    ///>
        NONBLOCK_SOCKET  = SOCK_NONBLOCK,   ///>
        SEQPACKET_SOCKET = SOCK_SEQPACKET   ///>
    };

    /**
     * @brief The IP_PROTOCOLS enum
     */
    enum IP_PROTOCOL : std::uint32_t {
        IP_AH       = IPPROTO_AH,
        IP_BEETPH   = IPPROTO_BEETPH,
        IP_COMP     = IPPROTO_COMP,
        IP_DCCP     = IPPROTO_DCCP,
        IP_DSPOPTS  = IPPROTO_DSTOPTS,
        IP_EGP      = IPPROTO_EGP,
        IP_ENCAP    = IPPROTO_ENCAP,
        IP_ESP      = IPPROTO_ESP,
        EP_ETHERNET = IPPROTO_ETHERNET,
        IP_FRAGMENT = IPPROTO_FRAGMENT,
        IP_GRE      = IPPROTO_GRE,
        IP_HOPOPTS  = IPPROTO_HOPOPTS,
        IP_ICMP     = IPPROTO_ICMP,
        IP_ICMPV6   = IPPROTO_ICMPV6,
        IP_IDP      = IPPROTO_IDP,
        IP_IGMP     = IPPROTO_IGMP,
        IP_IP       = IPPROTO_IP,
        IP_IPIP     = IPPROTO_IPIP,
        IP_IPV6     = IPPROTO_IPV6,
        IP_MH       = IPPROTO_MH,
        IP_MPLS     = IPPROTO_MPLS,
        IP_MPTCP    = IPPROTO_MPTCP,
        IP_MTP      = IPPROTO_MTP,
        IP_NONE     = IPPROTO_NONE,
        IP_PIM      = IPPROTO_PIM,
        IP_PUP      = IPPROTO_PUP,
        IP_RAW      = IPPROTO_RAW,
        IP_ROUTING  = IPPROTO_ROUTING,
        IP_RSVP     = IPPROTO_RSVP,
        IP_SCTP     = IPPROTO_SCTP,
        IP_TCP      = IPPROTO_TCP,
        IP_TP       = IPPROTO_TP,
        IP_UDP      = IPPROTO_UDP,
        IP_UDPLIT   = IPPROTO_UDPLITE
    };

    /**
     * @brief Connections families enumeration
     */
    enum CONNECTION_FAMILY : std::uint32_t {
        IB_SOCKET         = AF_IB,           ///>
        ALG_SOCKET        = AF_ALG,          ///>
        ASH_SOCKET        = AF_ASH,          ///>
        CAN_SOCKET        = AF_CAN,          ///>
        IPX_SOCKET        = AF_IPX,          ///>
        KCM_SOCKET        = AF_KCM,          ///>
        KEY_SOCKET        = AF_KEY,          ///>
        LCC_SOCKET        = AF_LLC,          ///>
        MAX_SOCKET        = AF_MAX,          ///>
        NFC_SOCKET        = AF_NFC,          ///>
        RDS_SOCKET        = AF_RDS,          ///>
        SMC_SOCKET        = AF_SMC,          ///>
        SNA_SOCKET        = AF_SNA,          ///>
        X25_SOCKET        = AF_X25,          ///>
        XDP_SOCKET        = AF_XDP,          ///>
        AX25_SOCKET       = AF_AX25,         ///>
        CAIF_SOCKET       = AF_CAIF,         ///>
        FILE_SOCKET       = AF_FILE,         ///>
        INET_SOCKET       = AF_INET,         ///>
        IPV4_SOCKET       = AF_INET,         ///>
        IRDA_SOCKET       = AF_IRDA,         ///>
        ISDN_SOCKET       = AF_ISDN,         ///>
        IUCV_SOCKET       = AF_IUCV,         ///>
        MPLS_SOCKET       = AF_MPLS,         ///>        
        ROSE_SOCKET       = AF_ROSE,         ///>
        TIPC_SOCKET       = AF_TIPC,         ///>
        UNIX_SOCKET       = AF_UNIX,         ///>
        INET6_SOCKET      = AF_INET6,        ///>
        IPV6_SOCKET       = AF_INET6,        ///>
        LOCAL_SOCKET      = AF_LOCAL,        ///>
        PPPOX_SOCKET      = AF_PPPOX,        ///>
        ROUTE_SOCKET      = AF_ROUTE,        ///>
        RXRPC_SOCKET      = AF_RXRPC,        ///>
        VSOCK_SOCKET      = AF_VSOCK,        ///>
        ATMPVC_SOCKET     = AF_ATMPVC,       ///>
        ATMSVC_SOCKET     = AF_ATMSVC,       ///>
        BRIDGE_SOCKET     = AF_BRIDGE,       ///>
        DECnet_SOCKET     = AF_DECnet,       ///>
        ECONET_SOCKET     = AF_ECONET,       ///>
        NETROM_SOCKET     = AF_NETROM,       ///>
        PACKET_SOCKET     = AF_PACKET,       ///>
        PHONET_SOCKET     = AF_PHONET,       ///>
        UNSPEC_SOCKET     = AF_UNSPEC,       ///>
        NETBEUI_SOCKET    = AF_NETBEUI,      ///>
        NETLINK_SOCKET    = AF_NETLINK,      ///>
        QIPCRTR_SOCKET    = AF_QIPCRTR,      ///>
        WANPIPE_SOCKET    = AF_WANPIPE,      ///>
        SECURITY_SOCKET   = AF_SECURITY,     ///>
        APPLETALK_SOCKET  = AF_APPLETALK,    ///>
        BLUETOOTH_SOCKET  = AF_BLUETOOTH,    ///>
        IEEE802154_SOCKET = AF_IEEE802154,   ///>
    };

    #elif  // __linux

    #endif // __linux
}

#endif
