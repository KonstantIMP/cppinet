#ifndef  HOST_INFO_HPP
#define  HOST_INFO_HPP

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
     * @brief Gets the aliases number.
     *
     * @return The aliases number.
     */
    std::size_t get_aliases_num() const;

    /**
     * @brief Gets the aliases vector.
     *
     * @return Vector with address aliases.
     */
    std::vector<std::string> get_aliases_vector() const;

    /**
     * @brief Gets the connection family.
     *
     * @return The connection family type from KonstantIMP::CONNECTION_FAMILY .
     */
    CONNECTION_FAMILY get_connection_family() const;

    /**
     * @brief Gets the addresses number.
     *
     * @return The addresses of host number.
     */
    std::size_t get_addresses_num() const;

    /**
     * @brief Gets the addresses vector.
     *
     * @return Vector with hosts addresses.
     */
    std::vector<std::string> get_addresses_vector();

    /**
     * @brief Assignment operator.
     *
     * @param[in]  copy  The copied object
     */
    void operator=(const host_info & copy);

    friend class dns;

private:
#ifdef   __linux
    /**
     * @brief Constructs a new instance.
     *
     * Set all data from DNS probe for linux
     *
     * @param[in] hi Linux host info struct
     */
    host_info(const hostent * hi);

#elif  //__linux

#endif //__linux

private:
    //// Host name
    std::string host_name;
    //// Connection family
    CONNECTION_FAMILY con_fam;
    //// Vector with hosts aliases
    std::vector<std::string> aliases;
    //// Vector with hosts addresses
    std::vector<std::string> addresses;

};

}

#endif //HOST_INFO_HPP
