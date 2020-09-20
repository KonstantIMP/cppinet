#include "../include/dns.hpp"

#ifdef    __linux

extern int h_errno;

#elif  // __linux

#endif // __linux

namespace KonstantIMP {

addess * dns::get_address_by_name(const std::string & name, const CONNECTION_FAMILY & con_fam,
                                  const SOCKET_TYPE & sock_type, const IP_PROTOCOL & ipproto) {
    #ifdef    __linux

    addrinfo * result;

    addrinfo hints;
    hints.ai_flags = AI_NUMERICHOST;
    /*hints.ai_family = static_cast<int>(con_fam);
    hints.ai_socktype = static_cast<int>(sock_type);
    hints.ai_protocol = static_cast<int>(ipproto);*/

    int error = getaddrinfo(name.c_str(), nullptr, &hints, &result);

    if(error) {
        freeaddrinfo(result);

        switch (error) {
            case EAI_FAMILY : throw dns_err('\"' + name + "has unsopported protocol family"); break;
            case EAI_SOCKTYPE : throw  dns_err('\"' + name + "\" has unsopported socket type"); break;
            case EAI_BADFLAGS : throw  dns_err("cppinet error. Incorrect flags"); break;
            case EAI_NONAME : throw dns_err("cppinet error. Incorrect node or hints"); break;
            case EAI_SERVICE : throw dns_err('\"' + name + "\" usupportde for " + std::to_string(sock_type) + " socket type"); break;
            case EAI_ADDRFAMILY : throw  dns_err('\"' + name + "\" doesn\'t have addresses in used family"); break;
            case EAI_NODATA : throw dns_err('\"' + name + "\" exists in DNS, but doesn\'t nave IP address"); break;
            case EAI_MEMORY : throw dns_err("Can\'t allocate memory for DNS work"); break;
            case EAI_FAIL : throw dns_err("DNS server rerurned block message"); break;
            case EAI_AGAIN : throw  dns_err("A temporary DNS-server ERROR. Try again later"); break;
            case EAI_SYSTEM : throw std::runtime_error("System error, while DNS worked");
            default: throw dns_err("Unspec error"); break;
        }
    }

    sockaddr_in a = *reinterpret_cast<sockaddr_in *>(result->ai_addr);

    //return reinterpret_cast<addess *>(new ipv4_address(a));

    #elif  // __linux

    #endif // __linux
}

}
