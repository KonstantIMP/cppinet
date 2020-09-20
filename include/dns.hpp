#ifndef DNS_HPP
#define DNS_HPP

/**
 * @file port.hpp
 * @author KonstantIMP
 */

#include "cppinet_defines.hpp"
#include "host_info.hpp"
#include "address.hpp"

#include <exception>
#include <stdexcept>
#include <string>

namespace KonstantIMP {

/**
 * @brief The dns_err class
 *
 * Exceprion class for DNS probes
 */
class dns_err : public std::exception {
public:
    /**
     * @brief dns_err Standart exception construcror
     * @param[in] msg Error message
     */
    dns_err(const std::string & msg) : err_msg(msg) {}

    /**
     * @brief what Error message getter
     * @return Error message
     */
    virtual const char* what() const noexcept {return err_msg.c_str();}

private:
    std::string err_msg;
};


class dns {
public:
    /**
     * @brief Gets the address by name.
     *
     * @param[in] name The host name
     *
     * @param[in] con_fam Priarity connection family
     *
     * @throw dns_err if name hasn't found in DNS
     * 
     * @return The host_info for the searched name.
     */
    static addess * get_address_by_name(const std::string & name, const CONNECTION_FAMILY & con_fam = UNSPEC_SOCKET,
                                   const SOCKET_TYPE & sock_type = STREAM_SOCKET, const IP_PROTOCOL & ipproto = IP_TCP);

    /**
     * @brief Gets the host by address.
     *
     * @param[in] addr address object
     *
     * @throw dns_err if address hasn't found in DNS
     * 
     * @return The host_info for the searched address.
     */
    //static host_info get_host_by_address(const address & addr);
};

}

#endif // DNS_HPP
