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

#elif  // __linux

#endif // __linux

namespace KonstantIMP {

class address {
public:
    address();

    CONNECTION_FAMILY get_con_fam() const;

    std::size_t get_sys_addr_size() const;

    virtual void * get_sys_addr() const = 0;

protected:
    CONNECTION_FAMILY con_fam;

    std::size_t sys_addr_size;
};

class ipv4_address : public address {
public:

    #ifdef    __linux
    ipv4_address(const sockaddr_in & addr, const port & p = port(80));

    void set_sys_addr(const sockaddr_in & addr);

    sockaddr_in get_system_addr() const;
    #elif  // __linux

    #endif // __linux

    void set_port(const port & p);
    port get_port() const;

    virtual void * get_sys_addr() const;

private:
    #ifdef    __linux
    sockaddr_in sys_addr;
    #elif  // __linux

    #endif // __linux

    port con_port;
};

}

#endif //ADDRESS_HPP
