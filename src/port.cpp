#include "../include/port.hpp"

#include <netinet/in.h>
#include <arpa/inet.h>

namespace KonstantIMP {

port::port(const port & copy) {
    this->host_long = copy.host_long;
}

port::port(const uint32_t & hl) : host_long(hl) {}

uint32_t port::host_to_network_long(const uint32_t & hl) {
    return htonl(hl);
}

uint16_t port::host_to_network_short(const uint16_t & hs) {
    return htons(hs);
}

uint32_t port::network_to_host_long(const uint32_t & nl) {
    return ntohl(nl);
}

uint16_t port::network_to_host_short(const uint16_t & ns) {
    return ntohs(ns);
}

uint32_t port::as_network_long() const {
    return port::host_to_network_long(host_long);
}

void port::operator=(const port & copy) {
    this->host_long = copy.host_long;
}

}
