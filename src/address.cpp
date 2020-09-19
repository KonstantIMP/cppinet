#include "../include/address.hpp"

namespace KonstantIMP {

address::address() : con_fam(UNSPEC_SOCKET), sys_addr_size(0) {}

CONNECTION_FAMILY address::get_con_fam() const {
    return con_fam;
}

std::size_t address::get_sys_addr_size() const {
    return sys_addr_size;
}

}
