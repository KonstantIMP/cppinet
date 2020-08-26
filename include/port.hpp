#ifndef PORT_HPP
#define PORT_HPP

#include <cstdint>

namespace KonstantIMP {

class port {
public:
    explicit port(const port &);
    explicit port(const std::uint32_t &);

    static std::uint32_t host_to_network_long(const std::uint32_t &);
    static std::uint16_t host_to_network_short(const std::uint16_t &);

    static std::uint32_t network_to_host_long(const std::uint32_t &);
    static std::uint16_t network_to_host_short(const std::uint16_t &);

    std::uint32_t as_network_long() const;

    void operator=(const port &);

private:
    std::uint32_t host_long;
};

}

#endif // PORT_HPP
