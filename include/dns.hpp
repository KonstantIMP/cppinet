#ifndef DNS_HPP
#define DNS_HPP

#include "cppinet_defines.hpp"
#include "host_info.hpp"

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
     * @brief Gets the host by name.
     *
     * @param[in] name The host name
     *
     * @throw dns_err if name hasn't found in DNS
     * 
     * @return The host_info for the searched name.
     */
    static host_info get_host_by_name(const std::string & name);

    /**
     * @brief Gets the host by address.
     *
     * @param[in] addr address object
     *
     * @throw dns_err if address hasn't found in DNS
     * 
     * @return The host_info for the searched address.
     */
    //static host_info get_host_by_addr(const address & addr);
    
    /**
     * @brief Gets the host by address.
     *
     * @param[in] addr The searched address in str
     * @param[in] con_fam The searched addresses conection family
     *
     * @throw dns_err if address hasn't found in DNS
     * 
     * @return The host_info for the searched address.
     */
    static host_info get_host_by_addr(const std::string & addr, const CONNECTION_FAMILY & con_fam);

};

}

#endif // DNS_HPP
