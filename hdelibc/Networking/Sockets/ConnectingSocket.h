#ifndef CONNECTINGSOCKET_H
#define CONNECTINGSOCKET_H

#include <stdio.h>
#include "SimpleSocket.h"

namespace HDE
{
    class ConnectingSocket: public SimpleSocket
    {
    public:
        ConnectingSocket(int domain, int service, int protocol, int port, u_long interface);
        void connect_to_network(int sock, struct sockaddr_in address);
    };
}

#endif /* CONNECTINGSOCKET_H */