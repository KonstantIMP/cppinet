#include <iostream>

#include "../include/socket.hpp"
#include "../include/dns.hpp"

int main() {
    KonstantIMP::u_socket t;

    t.open(KonstantIMP::IPV4_SOCKET, KonstantIMP::STREAM_SOCKET);

    int yes = 1;

    t.set_opt(SOL_SOCKET, SO_REUSEADDR, &yes, sizeof (int));

    t.bind_to(std::shared_ptr<KonstantIMP::address>(new KonstantIMP::ipv4_address("0.0.0.0", KonstantIMP::port(3425))));

    t.listen_socket(5);

    auto cl = t.accept_connection();

    cl->send_line("Woof");

    std::cout << cl->recieve_line(true);

    KonstantIMP::ipv4_address h(cl->get_addr_inf().get());

    std::cout << h.get_ip_address() << "\n";

    cl->close_s();

    t.close_s();

    return 0;
}
