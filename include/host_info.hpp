#ifndef  HOST_INFO_HPP
#define  HOST_INFO_HPP

/**
 * @file port.hpp
 * @author KonstantIMP
 */

#include "cppinet_defines.hpp"

#ifdef   __linux

#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#elif  //__linux

#endif //__linux

#include <vector>
#include <string>

namespace KonstantIMP {

class host_info {
public:
    /**
     * @brief Constructs a new instance.
     *
     * Sets all data as localhost
     */
    host_info();

    /**
     * @brief Constructs a new instance from another object
     *
     * @param[in] copy The copied object
     */
    host_info(const host_info & copy);

    /**
     * @brief Gets the host name.
     *
     * @return The host name.
     */
    std::string get_host_name() const;

    /**
     * @brief Gets the connection family.
     *
     * @return The connection family type from KonstantIMP::CONNECTION_FAMILY .
     */
    CONNECTION_FAMILY get_connection_family() const;

    /**
     * @brief Gets the address.
     *
     * @return The address of host.
     */
    std::string get_address() const;

    /**
     * @brief Assignment operator.
     *
     * @param[in]  copy  The copied object
     */
    void operator=(const host_info & copy);

    friend class dns;

private:
    host_info(const std::string & host_n, const std::string & host_a, const CONNECTION_FAMILY & con);

private:
    //// Host name
    std::string host_name;
    /// Host address
    std::string host_addr;
    //// Connection family
    CONNECTION_FAMILY con_fam;
};

}

#endif //HOST_INFO_HPP
