#include "../include/socket.hpp"

#ifdef __linux

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>
#include <errno.h>
#include <cstdio>

extern int errno;

#elif

#endif

#include <iostream>

namespace KonstantIMP {

u_socket::u_socket() {
    #ifdef __linux

    con_fam = KonstantIMP::CONNECTION_FAMILY::UNSPEC_SOCKET;
    sock_t = SOCKET_TYPE::STREAM_SOCKET;
    proto_num = sock_fd = 0;

    #elif

#endif
}

void u_socket::open(const CONNECTION_FAMILY & con_family, const SOCKET_TYPE & sock_type, const uint8_t & proto) {
    #ifdef __linux

    if(sock_fd) throw socket_err("Socket have already opened");

    sock_fd = socket(static_cast<int>(con_family), static_cast<int>(sock_type), static_cast<int>(proto));

    if(sock_fd == -1) {
        sock_fd = 0;

        switch (errno) {
            case EPROTONOSUPPORT : throw socket_err("Used protocol not supported in this domain"); break;
            case EAFNOSUPPORT : throw socket_err("This protocol family doen\'t supprot used protocol"); break;
            case ENFILE : throw socket_err("Need more memory to create socket"); break;
            case EMFILE : throw socket_err("Too mush files processes"); break;
            case EACCES : throw socket_err("You don\'t have acces to create socket"); break;
            case ENOBUFS : throw socket_err("Need more memory to create socket"); break;
            case ENOMEM : throw socket_err("Need more memory to create socket"); break;
            case EINVAL : throw socket_err("Unspec protocol or unsopported protocols collection"); break;
            default: throw socket_err("Undefined error"); break;
        }
    }

    con_fam = con_family;
    sock_t = sock_type;
    proto_num = proto;

    #elif

#endif
}

void u_socket::bind_to(const std::shared_ptr<address> & binded_addr) {
    #ifdef __linux

    if(sock_fd == 0) throw socket_err("Socket hasn\'t opened yet");
    if(con_fam != binded_addr->get_con_fam()) throw socket_err("Can\'t bind socket. Different binded address family");

    if(bind(sock_fd, reinterpret_cast<sockaddr *>(binded_addr->get_sys_addr().get()), binded_addr->get_sys_addr_size()) == -1) {
        switch (errno) {
            case EBADF : throw socket_err("Incorrect socket descriptor"); break;
            case EINVAL : throw socket_err("Socket have already binded"); break;
            case EACCES : throw socket_err("You don\'t have acces to create socket"); break;
            case ENOTSOCK : throw socket_err("Socket deskriptor is file deskriptoe?"); break;
            default: throw socket_err("Undefined error"); break;
        }
    }

    #elif

#endif
}

void u_socket::connect_to(const std::shared_ptr<address> & binded_addr) {
#ifdef __linux

    if(sock_fd == 0) throw socket_err("Socket hasn\'t opened yet");
    if(con_fam != binded_addr->get_con_fam()) throw socket_err("Can\'t bind socket. Different binded address family");

    //std::cout << port::network_to_host_short(reinterpret_cast<sockaddr_in *>(binded_addr->get_sys_addr().get())->sin_port) << '\n';

    if(connect(sock_fd, reinterpret_cast<sockaddr *>(binded_addr->get_sys_addr().get()), binded_addr->get_sys_addr_size()) == -1) {
        switch (errno) {
            case EBADF : throw socket_err("Incorrect socket descriptor"); break;
            case EINVAL : throw socket_err("Socket have already binded"); break;
            case EACCES : throw socket_err("You don\'t have acces to create socket"); break;
            case ENOTSOCK : throw socket_err("Socket deskriptor is file deskriptoe?"); break;
            default: throw socket_err("Undefined error"); break;
        }
    }

#elif

#endif
}

void u_socket::shutdown_s() {
#ifdef __linux

    if(sock_fd == 0) throw socket_err("Socket hasn\'t opened yet");

    if(shutdown(sock_fd, SHUT_RDWR) == -1) {
        switch (errno) {
            case EBADF : throw socket_err("Incorrect socket descriptor"); break;
            case EINVAL : throw socket_err("Incorrect arguments"); break;
            case ENOTCONN : throw socket_err("Socket hasn\'t been connected yet"); break;
            case ENOTSOCK : throw socket_err("Socket deskriptor is file deskriptoe?"); break;
            default: throw socket_err("Undefined error"); break;
        }
    }

    sock_fd = 0;

#elif

#endif
}

void u_socket::close_s() {
#ifdef __linux

    if(sock_fd == 0) throw socket_err("Socket hasn\'t opened yet");

    if(close(sock_fd) == -1) {
        switch (errno) {
            case EBADF : throw socket_err("Incorrect socket descriptor"); break;
            case EINTR : throw socket_err("Closing was inerrupted"); break;
            case EIO : throw socket_err("Input/output error"); break;
            default: throw socket_err("Undefined error"); break;
        }
    }

    sock_fd = 0;

#elif

#endif
}

}
