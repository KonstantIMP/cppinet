#include <iostream>

#include "../include/socket.hpp"
#include "../include/dns.hpp"

int main() {
    KonstantIMP::u_socket t;

    t.open(KonstantIMP::IPV4_SOCKET, KonstantIMP::STREAM_SOCKET);

    KonstantIMP::address * me = new KonstantIMP::ipv4_address("127.0.0.1", KonstantIMP::port(3425));

    t.connect_to(std::shared_ptr<KonstantIMP::address>(me));

    char buf[10]; std::memset(buf, 0, 10);
    std::strcpy(buf, "Woof!\r\n");

    std::cout << t.send_packet(buf, sizeof (buf)) << '\n';

    std::memset(buf, 0, 10);

    std::cout << t.recieve_packet(buf, 5) << ' ' << buf;

    t.close_s();

    return 0;
}
