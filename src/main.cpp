#include <iostream>

#include "../include/socket.hpp"
#include "../include/dns.hpp"

int main() {
    KonstantIMP::u_socket t;

    t.open(KonstantIMP::IPV4_SOCKET, KonstantIMP::STREAM_SOCKET);

    KonstantIMP::address * me = new KonstantIMP::ipv4_address("127.0.0.1", KonstantIMP::port(3425));

    t.connect_to(std::shared_ptr<KonstantIMP::address>(std::shared_ptr<KonstantIMP::address>(me)));

    //std::cout << KonstantIMP::port::network_to_host_short(reinterpret_cast<sockaddr_in *>(me->get_sys_addr().get())->sin_port) << '\n';
    //std::cout << inet_ntoa(reinterpret_cast<sockaddr_in *>(me->get_sys_addr().get())->sin_addr) << '\n';

    t.close_s();

    return 0;
}
