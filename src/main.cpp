#include <iostream>

#include "../include/port.hpp"

int main() {
    std::cout << "Port 80 is " << KonstantIMP::port::host_to_network_long(80) << " in network long\n";
    std::cout << "Port 80 is " << KonstantIMP::port::host_to_network_short(80) << " in network short\n";
    return 0;
}
