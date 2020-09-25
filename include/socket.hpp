#ifndef SOCKET_HPP
#define SOCKET_HPP

#include "cppinet_defines.hpp"

#include "address.hpp"

namespace KonstantIMP {

class socket_err : public std::exception {
public:
    socket_err(const std::string & msg) : err_msg(msg) {}

    virtual const char* what() const noexcept {return err_msg.c_str();}

private:
    std::string err_msg;
};

class u_socket {
public:
    u_socket();
    virtual ~u_socket() {};

    virtual void open(const CONNECTION_FAMILY & con_family, const SOCKET_TYPE & sock_type, const std::uint8_t & proto = 0);

    virtual void bind_to(const std::shared_ptr<address> & binded_addr);

    virtual void connect_to(const std::shared_ptr<address> & binded_addr);

    virtual std::size_t send_packet(const char * msg, const std::size_t & msg_size);
    virtual std::size_t recieve_packet(char * data, const std::size_t & data_size);

    virtual void send_line(const std::string & msg);
    virtual std::string recieve_line(const bool & save_rn = false);

    virtual void shutdown_s();
    virtual void close_s();

    virtual void set_opt(const int & opt_level, const int & opt_name, void * opt_data, const std::size_t & opt_len = sizeof (int));

    std::shared_ptr<address> get_addr_inf() const;

private:
    std::shared_ptr<address> addr_info;

    #ifdef __linux

    CONNECTION_FAMILY con_fam;

    std::uint8_t proto_num;

    SOCKET_TYPE sock_t;

    int sock_fd;

    #elif

    #endif
};

}

#endif // SOCKET_HPP
