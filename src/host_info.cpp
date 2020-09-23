#include "../include/host_info.hpp"

namespace KonstantIMP {

host_info::host_info() : host_name("localhost"), host_addr("127.0.0.1"), con_fam(LOCAL_SOCKET) {}

host_info::host_info(const host_info & copy) {
    this->operator=(copy);
}

std::string host_info::get_host_name() const {
    return host_name;
}

CONNECTION_FAMILY host_info::get_connection_family() const {
    return con_fam;
}

std::string host_info::get_address() const {
    return host_addr;
}

void host_info::operator=(const host_info & copy) {
    host_name = copy.host_name;
    host_addr = copy.host_addr;
    con_fam = copy.con_fam;
}

KonstantIMP::host_info::host_info(const std::string & host_n, const std::string & host_a, const KonstantIMP::CONNECTION_FAMILY & con) {
    host_name = host_n;
    host_addr = host_a;
    con_fam = con;
}

}
