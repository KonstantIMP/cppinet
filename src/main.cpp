#include <iostream>

#include "../include/socket.hpp"
#include "../include/dns.hpp"

int main() {
    KonstantIMP::u_socket t;

    t.open(KonstantIMP::IPV4_SOCKET, KonstantIMP::STREAM_SOCKET);

    int yes = 1;

    t.set_opt(SOL_SOCKET, SO_REUSEADDR, &yes, sizeof (int));

    KonstantIMP::address * me = new KonstantIMP::ipv4_address("127.0.0.1", KonstantIMP::port(3425));
    t.bind_to(std::shared_ptr<KonstantIMP::address>(me));



    return 0;
}
