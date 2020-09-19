#ifndef PORT_HPP
#define PORT_HPP

/**
 * @file port.hpp
 * @author KonstantIMP
 */

#include "cppinet_defines.hpp"

#ifdef    __linux

#include <arpa/inet.h>

#elif  // __linux

#endif // __linux

namespace KonstantIMP {

class port {
public :
    
    /**
     * @brief Constructs a new instance.
     *
     * Need to copy info from another KonstantIMP::port object
     * 
     * @param[in] copy The copied object
     */
    port(const port & copy);

    /**
     * @brief      Constructs a new instance.
     *
     * Default constructor. Sets port value as zero
     *
     * @param[in] port The port num (zero by default)
     */
    port(const std::uint32_t & port = 0);


    /**
     * @brief Gets as host.
     *
     * @return Returns port value in host byte order
     */
    std::uint32_t get_as_host() const;

    /**
     * @brief Gets as network.
     *
     * @return Returns port value as network(big-endian) byte order
     */
    std::uint32_t get_as_network() const;


    /**
     * @brief Convert long port value from host to network byte order
     *
     * @param[in] h_port The host port value
     *
     * @return host value in network byte order
     */
    static std::uint32_t host_to_network_long(const std::uint32_t & h_port);

    /**
     * @brief Convert long port value from network to host byte order
     *
     * @param[in] be_port The port in network byte order
     *
     * @return host value in host byte order
     */
    static std::uint32_t network_to_host_long(const std::uint32_t & be_port);


    /**
     * @brief Convert short port value from network to host byte order
     *
     * @param[in] h_port The host port value
     *
     * @return host value in netwok byte order
     */
    static std::uint16_t network_to_host_short(const std::uint16_t & h_port);

    /**
     * @brief Conver short port value from host to network byte order
     *
     * @param[in] be_port The port in network byte order
     *
     * @return host value in host byte order
     */
    static std::uint16_t host_to_network_short(const std::uint16_t & be_port);
    

    /**
     * @brief Assignment operator.
     *
     * @param[in] copy The copied object
     */
    void operator=(const port & copy);

    /**
     * @brief Assignment operator.
     *
     * @param[in] h_port The host byte order port value
     */
    void operator=(const std::uint32_t & h_port);


    /**
     * @brief Equality operator.
     *
     * @param[in] equal The equaled object
     *
     * @return The result of the equality
     */
    bool operator==(const port & equal) const;

private:
    //// Port value
    std::uint32_t host_port;
};

}

#endif //PORT_HPP
