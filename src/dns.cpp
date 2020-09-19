#include "../include/dns.hpp"

#ifdef    __linux

extern int h_errno;

#elif  // __linux

#endif // __linux

namespace KonstantIMP {

host_info dns::get_host_by_name(const std::string & name) {
    #ifdef    __linux

    hostent * searched_host = gethostbyname(name.c_str());

    if(searched_host == nullptr) {
        switch (h_errno) {
            case HOST_NOT_FOUND : throw dns_err("The \"" + name + "\" not found in DNS"); break;
            case NO_ADDRESS : throw dns_err('\"' + name + "\" exists in DNS, but doesn\'t nave IP address"); break;
            case NO_RECOVERY : throw  dns_err("DNS-server critical ERROR"); break;
            case TRY_AGAIN : throw  dns_err("A temporary DNS-server ERROR. Try again later"); break;
            default: throw dns_err("Unspec error"); break;
        }
    }
    else return host_info(searched_host);

    #elif  // __linux

    #endif // __linux
}

host_info dns::get_host_by_addr(const std::string & addr, const CONNECTION_FAMILY & con_fam) {
    #ifdef    __linux

    hostent * searched_host = gethostbyaddr(addr.c_str(), static_cast<socklen_t>(addr.length()), static_cast<int>(con_fam));

    if(searched_host == nullptr) {
        switch (h_errno) {
            case HOST_NOT_FOUND : throw dns_err("The \"" + addr + "\" not found in DNS"); break;
            case NO_ADDRESS : throw dns_err('\"' + addr + "\" exists in DNS, but doesn\'t nave IP address"); break;
            case NO_RECOVERY : throw  dns_err("DNS-server critical ERROR"); break;
            case TRY_AGAIN : throw  dns_err("A temporary DNS-server ERROR. Try again later"); break;
            default: throw dns_err("Unspec error"); break;
        }
    }
    else return host_info(searched_host);

    #elif  // __linux

    #endif // __linux
}

}
