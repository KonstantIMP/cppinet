#include "../include/address.hpp"

namespace KonstantIMP {

address::address() : con_fam(UNSPEC_SOCKET), sys_addr_size(0) {}

CONNECTION_FAMILY address::get_con_fam() const {
    return con_fam;
}

std::size_t address::get_sys_addr_size() const {
    return sys_addr_size;
}



ipv4_address::ipv4_address(const address *parent) : address(), ip_address(""), con_port(port(80)) {
    con_fam = IPV4_SOCKET;

    #ifdef   __linux
    sys_addr_size = sizeof (sockaddr_in);

    ip_address = inet_ntoa(reinterpret_cast<sockaddr_in *>(parent->get_sys_addr().get())->sin_addr);
    #elif  //__linux

    #endif //__linux
}

ipv4_address::ipv4_address(const std::string & ip, const port & p, const CONNECTION_FAMILY & cf) :
    address(), ip_address(ip), con_port(p) {
    con_fam = cf;

    #ifdef   __linux
    sys_addr_size = sizeof (sockaddr_in);
    #elif  //__linux

    #endif //__linux
}

void ipv4_address::set_ip_address(const std::string & ip) {
    if(inet_aton(ip.c_str(), nullptr) == 0) throw std::runtime_error('\'' + ip + "\' is incorrect IPv4 address");
    ip_address = ip;
}

std::string ipv4_address::get_ip_address() const {
    return ip_address;
}

void ipv4_address::set_port(const port & p) {
    con_port = p;
}

port ipv4_address::get_port() const {
    return con_port;
}

std::shared_ptr<char> ipv4_address::get_sys_addr() const {
    #ifdef   __linux

    sockaddr_in * tmp = new sockaddr_in;
    std::memset(tmp, 0, sizeof (sockaddr_in));

    tmp->sin_family = IPV4_SOCKET;
    tmp->sin_port = port::host_to_network_short(con_port.get_as_host());
    tmp->sin_family = static_cast<int>(con_fam);

    if(inet_aton(ip_address.c_str(), &tmp->sin_addr) == 0) throw std::runtime_error('\'' + ip_address + "\' is incorrect IP address");

    return std::shared_ptr<char>(reinterpret_cast<char *>(tmp));

    #elif  //__linux

#endif //__linux
}

bool ipv4_address::operator==(const ipv4_address & equal) const {
    return (this->ip_address == equal.ip_address) && (this->con_port == equal.con_port) && (this->con_fam == equal.con_fam);
}

bool ipv4_address::operator==(const address * equal) const {
    return this->operator==(ipv4_address(equal));
}

}
