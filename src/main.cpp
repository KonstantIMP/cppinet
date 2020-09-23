#include <iostream>

#include "../include/dns.hpp"
#include "../include/address.hpp"

#include <memory>


int main() {
    auto a = KonstantIMP::dns::get_address_by_name("lr-in-f101.1e100.net");

    std::cout << "google.com\n";

    for(auto & iter : a) {
        KonstantIMP::ipv4_address c(iter.get());

        std::cout << '\t' << c.get_ip_address() << ':' << c.get_port().get_as_host() << '\n';
    }

    KonstantIMP::host_info g = KonstantIMP::dns::get_host_by_address(*a.at(0).get());

    std::cout << g.get_host_name() << '\n';

    return 0;
}
