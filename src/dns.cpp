#include "../include/dns.hpp"

#include <set>

#ifdef    __linux

extern int h_errno;

#elif  // __linux

#endif // __linux

namespace KonstantIMP {

std::vector<std::shared_ptr<address>> dns::get_address_by_name(const std::string & name) {
    #ifdef    __linux

    addrinfo * result;

    int error = getaddrinfo(name.c_str(), nullptr, nullptr, &result);

    if(error) {
        freeaddrinfo(result);

        switch (error) {
            case EAI_FAMILY : throw dns_err('\"' + name + "has unsopported protocol family"); break;
            case EAI_SOCKTYPE : throw  dns_err('\"' + name + "\" has unsopported socket type"); break;
            case EAI_BADFLAGS : throw  dns_err("cppinet error. Incorrect flags"); break;
            case EAI_NONAME : throw dns_err("cppinet error. Incorrect node or hints"); break;
            case EAI_SERVICE : throw dns_err('\"' + name + "\" usupportde for " + std::to_string(result->ai_socktype) + " socket type"); break;
            case EAI_ADDRFAMILY : throw  dns_err('\"' + name + "\" doesn\'t have addresses in used family"); break;
            case EAI_NODATA : throw dns_err('\"' + name + "\" exists in DNS, but doesn\'t nave IP address"); break;
            case EAI_MEMORY : throw dns_err("Can\'t allocate memory for DNS work"); break;
            case EAI_FAIL : throw dns_err("DNS server rerurned block message"); break;
            case EAI_AGAIN : throw  dns_err("A temporary DNS-server ERROR. Try again later"); break;
            case EAI_SYSTEM : throw std::runtime_error("System error, while DNS worked");
            default: throw dns_err("Unspec error"); break;
        }
    }

    std::vector<std::shared_ptr<address>> ip_addr;

    if(result->ai_family == static_cast<int>(IPV4_SOCKET)) {
        addrinfo * tmp = result->ai_next;
        while (tmp != nullptr) {
            ip_addr.push_back(std::shared_ptr<address>(new ipv4_address(inet_ntoa(reinterpret_cast<sockaddr_in *>(tmp->ai_addr)->sin_addr), port(80), IPV4_SOCKET)));
            tmp = tmp->ai_next;
        }

        std::shared_ptr<address> zero = std::shared_ptr<address>(new ipv4_address("0.0.0.0", port(80), IPV4_SOCKET));
        for(std::size_t i{ip_addr.size() - 1}; i > 0; i--) {
            if(ip_addr.at(i)->operator==(zero.get())) {
                auto iter = ip_addr.begin();
                for(std::size_t j{0}; j < i; j++) {iter++;}
                ip_addr.erase(iter);
            }
        }

        //ip_addr.at(0).swap(ip_addr.at(ip_addr.size() - 1));

        freeaddrinfo(result);
    }
    else {

    }

    for(std::size_t i{ip_addr.size() - 1}; i > 0; i--) {
        if(ip_addr.at(i)->operator==(ip_addr.at(i - 1).get())) {
            auto iter = ip_addr.begin();
            for(std::size_t j{0}; j < i; j++) {iter++;}
            ip_addr.erase(iter);
        }
    }

    return ip_addr;

    #elif  // __linux

#endif // __linux
}

host_info dns::get_host_by_address(const address & addr) {
    #ifdef __linux
    char nbuf[1025]; std::memset(nbuf, 0, 1025);
    getnameinfo(reinterpret_cast<sockaddr *>(addr.get_sys_addr().get()), addr.get_sys_addr_size(), nbuf, 1025, nullptr, 0, 0);

    std::string address = "";
    if(addr.get_con_fam() == IPV4_SOCKET) {
        address = ipv4_address(&addr).get_ip_address();
    }
    else {
        //address = ipv6_address(&addr).get_ip_address();
    }

    return host_info(nbuf, address, addr.get_con_fam());
    #elif

    #endif
}

}
