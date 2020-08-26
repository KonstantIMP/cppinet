#ifndef SOCKET_HPP
#define SOCKET_HPP

#include "cppinet_defines.hpp"

#include <exception>
#include <cstddef>
#include <string>

namespace KonstantIMP {

class socket_err : public std::exception {
    socket_err(const std::string & msg) : err_msg(msg) {}

    virtual const char* what() const noexcept {return err_msg.c_str();}

private:
    std::string err_msg;
};


class socket {
    bool is_open() const;
    operator bool() const;

    void open(const SOCKET_FAMILY &, const SOCKET_TYPE &, const int & = 0);

    void listen(const std::size_t &);

    std::size_t send_packet(const char *, const std::size_t &);
    std::size_t recieve_line(const char *, const std::size_t &);

    void send_line(const std::string &);
    std::string recieve_line();

    void shutdown();
    void close();
private:
    int socket_fd;
};

}

#endif // SOCKET_HPP
