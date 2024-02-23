#ifndef SIMPLESOCKET_H
#define SIMPLESOCKET_H

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

namespace HDE
{
    class SimpleSocket
    {
    private:
        int sock;
        struct sockaddr_in address;
    public:
        SimpleSocket(int domain, int service, int protocol, int port, u_long interface);
        virtual void connect_to_network(int sock, struct sockaddr_in address) = 0;
        void test_connection(int item_to_test);
        int get_sock();
        struct sockaddr_in get_address();

    };
}

#endif /* SIMPLESOCKET_H */