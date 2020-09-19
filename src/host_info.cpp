#include "../include/host_info.hpp"

namespace KonstantIMP {

host_info::host_info() : host_name("localhost"), con_fam(LOCAL_SOCKET), aliases(),
    addresses(std::vector<std::string>{"127.0.0.1", "0.0.0.0"}) {}

host_info::host_info(const host_info & copy) {
    this->operator=(copy);
}

std::string host_info::get_host_name() const {
    return host_name;
}

std::size_t host_info::get_aliases_num() const {
    return aliases.size();
}

std::vector<std::string> host_info::get_aliases_vector() const {
    return aliases;
}

CONNECTION_FAMILY host_info::get_connection_family() const {
    return con_fam;
}

std::size_t host_info::get_addresses_num() const {
    return addresses.size();
}

std::vector<std::string> host_info::get_addresses_vector() {
    return addresses;
}

void host_info::operator=(const host_info & copy) {
    host_name = copy.host_name;
    con_fam = copy.con_fam;

    aliases.clear(); addresses.clear();

    aliases = copy.aliases;
    addresses = copy.addresses;
}

#ifdef    __linux

host_info::host_info(const hostent * hi) {
    host_name = hi->h_name;

    std::size_t i{0};
    while (hi->h_aliases[i] != nullptr) {
        aliases.push_back(std::string(hi->h_aliases[i]));
        i++;
    } i = 0;

    con_fam = static_cast<CONNECTION_FAMILY>(hi->h_addrtype);

    while (hi->h_addr_list[i] != nullptr) {
        in_addr * tmp = reinterpret_cast<in_addr *>(hi->h_addr_list[i]);
        addresses.push_back(std::string(inet_ntoa(*tmp))); i++;
    }
}

#elif  // __linux

#endif // __linux

}
