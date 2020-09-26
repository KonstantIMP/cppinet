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

u_socket::u_socket() : addr_info(nullptr) {
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
            case EACCES : throw socket_err("You don\'t have acces to create socket"); break;
            case EINVAL : throw socket_err("Incorrect arguments"); break;
            case ELOOP : throw socket_err("Too many symbolic links were encountered in resolving addr"); break;
            case ENAMETOOLONG : throw socket_err("addr is too long"); break;
            case ENOENT : throw socket_err("A  component in the directory prefix of the socket pathname does not exist"); break;
            case EADDRINUSE : throw socket_err("Local address is already in use"); break;
            case EADDRNOTAVAIL : throw socket_err("Socket had not previously been bound"); break;
            case ENOMEM : throw socket_err("No memory available"); break;
            case ENOTDIR : throw socket_err("A component of the path prefix is not a directory"); break;
            case EROFS : throw socket_err("The socket inode would reside on a read-only filesystem"); break;
            case EBADF : throw socket_err("Socket deskriptor is file deskriptoe?"); break;
            case EFAULT : throw socket_err("Address class is ouside user space"); break;
            case ENOTSOCK : throw socket_err("Socket deskriptor is file deskriptoe?"); break;
            default: throw socket_err("Undefined error"); break;
        }
    }

    addr_info = binded_addr;

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

    addr_info = binded_addr;
#elif

#endif
}

std::size_t u_socket::send_packet(const char * msg, const std::size_t & msg_size) {
#ifdef __linux
    if(sock_fd == 0) throw socket_err("Socket hasn\'t opened yet");
    std::size_t sended_b = 0, need_to_send(msg_size);
    char * tmp_ptr = const_cast<char *>(msg);

    while(need_to_send && (sended_b != msg_size)) {
        if(tmp_ptr[0] == '\0') break;
        int e = send(sock_fd, tmp_ptr, 1, 0);

        if(e == -1) {
            switch (errno) {
                case EACCES : throw socket_err("Write permission is  denied"); break;
                case EAGAIN : throw socket_err("The  requested  operation  would  block, because the socket is nonblocking"); break;
                case EALREADY : throw socket_err("Another Fast Open is in progress"); break;
                case EBADF : throw socket_err("Socket deskriptor is file deskriptoe?"); break;
                case ECONNRESET : throw socket_err("Connection reset by peer"); break;
                case EDESTADDRREQ : throw socket_err("The socket is not connection-mode, and no peer address is set"); break;
                case EFAULT : throw socket_err("An invalid user space address was specified for an argument"); break;
                case EINTR : throw socket_err("A signal occurred before any  data  was  transmitted"); break;
                case EINVAL : throw socket_err("Invalid argument passed"); break;
                case EISCONN : throw socket_err("The connection-mode socket was connected already but a recipient was specified"); break;
                case EMSGSIZE : throw socket_err("The size of the message to be sent made this impossible"); break;
                case ENOBUFS : throw socket_err("The output queue for a network interface was full"); break;
                case ENOMEM : throw socket_err("No memory available"); break;
                case ENOTCONN : throw socket_err("The socket is not connected"); break;
                case ENOTSOCK : throw socket_err("Socket deskriptor is file deskriptoe?"); break;
                case EOPNOTSUPP : throw socket_err("Incorrects flags"); break;
                case EPIPE : throw socket_err("The  local  end  has  been  shut  down  on a connection oriented socket"); break;
                default: throw socket_err("Undefined error"); break;
            }
        }

        sended_b++; need_to_send--; tmp_ptr++;
    }

    return sended_b;

#elif

#endif
}

std::size_t u_socket::recieve_packet(char * data, const std::size_t & data_size) {
#ifdef __linux
    if(sock_fd == 0) throw socket_err("Socket hasn\'t opened yet");

    std::size_t recieved_b = 0; char * tmp_ptr = data;

    for(std::size_t i{0}; i < data_size; i++) {
        int e = recv(sock_fd, tmp_ptr, 1, 0);

        if(e == 0) break;
        if(e == -1) {
            switch (errno) {
                case EAGAIN : throw socket_err("The  requested  operation  would  block, because the socket is nonblocking"); break;
                case EBADF : throw socket_err("Socket deskriptor is file deskriptoe?"); break;
                case ECONNREFUSED : throw socket_err("A remote host refused to allow the network connection"); break;
                case EFAULT : throw socket_err("An invalid user space address was specified for an argument"); break;
                case EINTR : throw socket_err("A signal occurred before any  data  was  transmitted"); break;
                case EINVAL : throw socket_err("Invalid argument passed"); break;
                case ENOMEM : throw socket_err("No memory available"); break;
                case ENOTCONN : throw socket_err("The socket is not connected"); break;
                case ENOTSOCK : throw socket_err("Socket deskriptor is file deskriptoe?"); break;
                default: throw socket_err("Undefined error"); break;
            }
        }

        if(tmp_ptr[0] == '\0') break;

        recieved_b++; tmp_ptr++;
    }

    return recieved_b;
#elif

#endif
}

void u_socket::send_line(const std::string & msg) {
    #ifdef __linux
        if(sock_fd == 0) throw socket_err("Socket hasn\'t opened yet");

        int sent_b{0}; std::size_t need_to_sent{msg.length() + 2};

        std::string tmp = msg + "\r\n";

        while (need_to_sent) {
            sent_b = send(sock_fd, tmp.c_str(), need_to_sent, 0);

            if(sent_b == -1) {
                switch (errno) {
                    case EACCES : throw socket_err("Write permission is  denied"); break;
                    case EAGAIN : throw socket_err("The  requested  operation  would  block, because the socket is nonblocking"); break;
                    case EALREADY : throw socket_err("Another Fast Open is in progress"); break;
                    case EBADF : throw socket_err("Socket deskriptor is file deskriptoe?"); break;
                    case ECONNRESET : throw socket_err("Connection reset by peer"); break;
                    case EDESTADDRREQ : throw socket_err("The socket is not connection-mode, and no peer address is set"); break;
                    case EFAULT : throw socket_err("An invalid user space address was specified for an argument"); break;
                    case EINTR : throw socket_err("A signal occurred before any  data  was  transmitted"); break;
                    case EINVAL : throw socket_err("Invalid argument passed"); break;
                    case EISCONN : throw socket_err("The connection-mode socket was connected already but a recipient was specified"); break;
                    case EMSGSIZE : throw socket_err("The size of the message to be sent made this impossible"); break;
                    case ENOBUFS : throw socket_err("The output queue for a network interface was full"); break;
                    case ENOMEM : throw socket_err("No memory available"); break;
                    case ENOTCONN : throw socket_err("The socket is not connected"); break;
                    case ENOTSOCK : throw socket_err("Socket deskriptor is file deskriptoe?"); break;
                    case EOPNOTSUPP : throw socket_err("Incorrects flags"); break;
                    case EPIPE : throw socket_err("The  local  end  has  been  shut  down  on a connection oriented socket"); break;
                    default: throw socket_err("Undefined error"); break;
                }
            }

            need_to_sent -= static_cast<std::size_t>(sent_b);
            tmp = tmp.substr(sent_b);
        }
    #elif

#endif
}

std::string u_socket::recieve_line(const bool & save_rn) {
#ifdef __linux
    std::string res = "";

    char buf[2]; std::memset(buf, 0, 2);

    while (1) {
        int recv_b = recv(sock_fd, buf, 1, 0);

        if(recv_b == 0) break;
        if(recv_b == -1) {
            switch (errno) {
                case EAGAIN : throw socket_err("The  requested  operation  would  block, because the socket is nonblocking"); break;
                case EBADF : throw socket_err("Socket deskriptor is file deskriptoe?"); break;
                case ECONNREFUSED : throw socket_err("A remote host refused to allow the network connection"); break;
                case EFAULT : throw socket_err("An invalid user space address was specified for an argument"); break;
                case EINTR : throw socket_err("A signal occurred before any  data  was  transmitted"); break;
                case EINVAL : throw socket_err("Invalid argument passed"); break;
                case ENOMEM : throw socket_err("No memory available"); break;
                case ENOTCONN : throw socket_err("The socket is not connected"); break;
                case ENOTSOCK : throw socket_err("Socket deskriptor is file deskriptoe?"); break;
                default: throw socket_err("Undefined error"); break;
            }
        }

        res += buf[0];

        if(buf[0] == '\n') break;
    }

    if(save_rn == false) {
        if(res.at(res.length() - 1) == '\n') res = res.substr(0, res.length() - 1);
        if(res.at(res.length() - 1) == '\r') res = res.substr(0, res.length() - 1);
    }

    return res;
#elif

#endif
}

void u_socket::listen_socket(const std::size_t & queue_size) {
#ifdef __linux
    if(sock_fd == 0) throw socket_err("Socket hasn\'t opened yet");

    if(listen(sock_fd, queue_size) == -1) {
        switch (errno) {
            case EADDRINUSE : throw socket_err("Local address is already in use"); break;
            case EOPNOTSUPP : throw socket_err("The socket is not of a type that supports the listen() operation"); break;
            case EBADF : throw socket_err("Socket deskriptor is file deskriptoe?"); break;
            case ENOTSOCK : throw socket_err("Socket deskriptor is file deskriptoe?"); break;
            default: throw socket_err("Undefined error"); break;
        }
    }
#elif

#endif
}

std::shared_ptr<u_socket> u_socket::accept_connection() {
#ifdef __linux
    if(sock_fd == 0) throw socket_err("Socket hasn\'t opened yet");

    if(con_fam == IPV4_SOCKET) {
        sockaddr_in client_info; socklen_t sockadd_in_size = sizeof (sockaddr_in);
        std::memset(&client_info, 0, sockadd_in_size);

        int new_sock_fd = accept(sock_fd, reinterpret_cast<sockaddr *>(&client_info), &sockadd_in_size);

        if(new_sock_fd == -1) {

        }

        u_socket * client = new u_socket;
        client->proto_num = proto_num;
        client->sock_fd = new_sock_fd;
        client->con_fam = con_fam;
        client->sock_t = sock_t;

        client->addr_info = std::shared_ptr<address>(new ipv4_address(inet_ntoa(client_info.sin_addr), port::network_to_host_short(client_info.sin_port)));

        return std::shared_ptr<u_socket>(client);
    }
    else {

    }
#elif

#endif
}

void u_socket::shutdown_s() {
#ifdef __linux

    if(sock_fd == 0) throw socket_err("Socket hasn\'t opened yet");

    if(shutdown(sock_fd, SHUT_RDWR) == -1) {
        switch (errno) {
            case EINVAL : throw socket_err("Incorrect arguments"); break;
            case EPERM : throw socket_err("Socket broadcast didn\'t enabled"); break;
            case EADDRINUSE : throw socket_err("Local address is already in use"); break;
            case EADDRNOTAVAIL : throw socket_err("Socket had not previously been bound"); break;
            case EAFNOSUPPORT : throw socket_err("Connected address have incorrect connection family"); break;
            case EAGAIN : throw socket_err("Connection cannot be completed immediately"); break;
            case EALREADY : throw socket_err("Previous connection has not yet been completed"); break;
            case EBADF : throw socket_err("Socket deskriptor is file deskriptoe?"); break;
            case ECONNREFUSED : throw socket_err("Socket is being listened or had remote access"); break;
            case EFAULT : throw socket_err("Address class is ouside user space"); break;
            case EINPROGRESS : throw socket_err("Connection cannot be completed immediately"); break;
            case EINTR : throw socket_err("System call was inerrupted"); break;
            case EISCONN : throw socket_err("The socket is already connected"); break;
            case ENETUNREACH : throw socket_err("Network is unreachable"); break;
            case ENOTSOCK : throw socket_err("Socket deskriptor is file deskriptoe?"); break;
            case EPROTOTYPE : throw socket_err("The socket does not support  the  requested  communications protocol"); break;
            case ETIMEDOUT : throw socket_err("Timeout while attempting connection"); break;
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

void u_socket::set_opt(const int & opt_level, const int & opt_name, void * opt_data, const std::size_t & opt_len) {
#ifdef __linux
    if(sock_fd == 0) throw socket_err("Socket hasn\'t opened yet");

    if(setsockopt(sock_fd, opt_level, opt_name, opt_data, opt_len) == -1) {
        switch (errno) {
            case EINVAL : throw socket_err("Incorrect arguments"); break;
            case EBADF : throw socket_err("Socket deskriptor is file deskriptoe?"); break;
            case EFAULT : throw socket_err("Address class is ouside user space"); break;
            case ENOPROTOOPT : throw socket_err("The option is unknown at the level indicated"); break;
            case ENOTSOCK : throw socket_err("Socket deskriptor is file deskriptoe?"); break;
            default: throw socket_err("Undefined error"); break;
        }
    }
#elif

#endif
}

std::shared_ptr<address> u_socket::get_addr_inf() const {
    return addr_info;
}

}
