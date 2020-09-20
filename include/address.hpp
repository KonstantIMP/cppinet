#ifndef  ADDRESS_HPP
#define  ADDRESS_HPP

/**
 * @file cppinet_defines.hpp
 * @author KonstantIMP
 */

#include "cppinet_defines.hpp"
#include "port.hpp"

#ifdef    __linux

#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>

#elif  // __linux

#endif // __linux

#include <exception>
#include <stdexcept>

#include <cstring>
#include <string>
#include <memory>

namespace KonstantIMP {

class address {
public:
    address();
    virtual ~address() {};

    CONNECTION_FAMILY get_con_fam() const;

    std::size_t get_sys_addr_size() const;

    virtual std::shared_ptr<char> get_sys_addr() const = 0;

protected:
    CONNECTION_FAMILY con_fam;

    std::size_t sys_addr_size;
};

class ipv4_address : public address {
public:
    ipv4_address(const std::string & ip, const port & p = port(80), const CONNECTION_FAMILY & cf = IPV4_SOCKET);
    virtual ~ipv4_address() {};

    void set_ip_address(const std::string & ip);
    std::string get_ip_address() const;

    void set_port(const port & p);
    port get_port() const;

    virtual std::shared_ptr<char> get_sys_addr() const;

private:
    std::string ip_address;

    port con_port;
};

}

#endif //ADDRESS_HPP
