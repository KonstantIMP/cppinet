#include <iostream>

#include "../include/dns.hpp"

int main() {

    KonstantIMP::host_info a(KonstantIMP::dns::get_host_by_name("google.com"));

    std::cout << a.get_host_name() << '\n';

    for(auto & iter : a.get_addresses_vector()) std::cout << "\t" << iter << "\n";

    return 0;
}
