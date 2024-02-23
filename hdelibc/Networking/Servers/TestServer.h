#ifndef TESTSERVER_H
#define TESTSERVER_H

#include <stdio.h>
#include <cstring>
#include <unistd.h>

#include "SimpleServer.h"

namespace HDE
{
    class TestServer: public SimpleServer
    {
    private:
        char buffer[30000]{0};
        int new_socket;

        void accepter();
        void handler();
        void responder();
    public:  
        TestServer();
        void launch();
    };
}

#endif /* TESTSERVER_H */