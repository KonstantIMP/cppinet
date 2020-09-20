#include <iostream>

#include "../include/dns.hpp"
#include "../include/address.hpp"

#include <memory>


int main() {
    auto a = KonstantIMP::dns::get_address_by_name("google.com");

    std::cout << "google.com\n";

    for(auto & iter : a) {
        KonstantIMP::ipv4_address c(iter.get());

        std::cout << '\t' << c.get_ip_address() << '\n';
    }

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
