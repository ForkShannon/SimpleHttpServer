#ifndef BINDINGSOCKET_H
#define BINDINGSOCKET_H

#include <stdio.h>
#include "SimpleSocket.h"
namespace HDE
{
    class BindingSocket: public SimpleSocket
    {
    private:
        int binding;

        void connect_to_network(int sock, struct sockaddr_in address);

    public:
        BindingSocket(int domain, int service, int protocol, int port, u_long interface);

        int get_binding();
    };
}

#endif /* BINDINGSOCKET_H */