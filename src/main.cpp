#include <iostream>

#include "../include/dns.hpp"
#include "../include/address.hpp"

#include <memory>


int main() {
    KonstantIMP::address * a = new KonstantIMP::ipv4_address("127.0.0.1", KonstantIMP::port(752));

    sockaddr_in b = *reinterpret_cast<sockaddr_in *>(a->get_sys_addr().get());

    std::cout << inet_ntoa(b.sin_addr);

    //KonstantIMP::dns::get_address_by_name("google.com", KonstantIMP::IPV4_SOCKET);


    /*addrinfo * res;

    int err = getaddrinfo("google.com", nullptr, nullptr, &res);

    addrinfo * p = res;

    std::cout << p->ai_family << ' ' << KonstantIMP::IPV4_SOCKET << '\n';

    while(p != nullptr) {
        sockaddr_in ip = *reinterpret_cast<sockaddr_in *>(p->ai_addr);
        std::cout << inet_ntoa(ip.sin_addr) << '\n';
        p = p->ai_next;
    }*/

    //std::cout << a.get_host_name() << '\n';

    //for(auto & iter : a.get_addresses_vector()) std::cout << "\t" << iter << "\n";

    return 0;
}
