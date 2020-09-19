#include "../include/port.hpp"

namespace KonstantIMP {

port::port(const port & copy) {
    host_port = copy.get_as_host();
}

port::port(const std::uint32_t & h_port) {
    host_port = h_port;
}

uint32_t port::get_as_host() const {
    return host_port;
}

uint32_t port::get_as_network() const {
    return KonstantIMP::port::host_to_network_long(host_port);
}

uint32_t port::host_to_network_long(const uint32_t & h_port) {
    #ifdef   __linux
    return htonl(h_port);
    #elif  //__linux

    #endif //__linux
}

uint32_t port::network_to_host_long(const uint32_t & be_port) {
    #ifdef   __linux
    return ntohl(be_port);
    #elif  //__linux

    #endif //__linux
}

uint16_t port::network_to_host_short(const uint16_t & h_port) {
    #ifdef   __linux
    return ntohs(h_port);
    #elif  //__linux

    #endif //__linux
}

uint16_t port::host_to_network_short(const uint16_t & be_port) {
    #ifdef   __linux
    return htons(be_port);
    #elif  //__linux

    #endif //__linux
}

void port::operator=(const port & copy) {
    host_port = copy.get_as_host();
}

void port::operator=(const uint32_t & h_port) {
    host_port = h_port;
}

bool port::operator==(const port & equal) const {
    return (this->get_as_host() == equal.get_as_host() && this->get_as_network() == equal.get_as_network());
}

}
