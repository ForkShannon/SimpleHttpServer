#include "TestServer.h"

HDE::TestServer::TestServer()
:SimpleServer(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10)
{
    launch();
}

void HDE::TestServer::accepter()
{
    struct sockaddr_in address = get_socket()->get_address();
    socklen_t addrlen = sizeof(address);
    new_socket = accept(get_socket()->get_sock(),(struct sockaddr*)&address, (socklen_t*)&addrlen);
    read(new_socket, buffer, sizeof(buffer));
}

void HDE::TestServer::handler()
{
    std::cout << buffer << std::endl;
}

void HDE::TestServer::responder()
{
    char *hello = "hello form server";
    write(new_socket, hello, strlen(hello));
    close(new_socket);
}

void HDE::TestServer::launch()
{
    while(true)
    {
        std::cout << "===== WAITING =====" << std::endl;
        accepter();
        handler();
        responder();
        std::cout << "===== DONE =====" << std::endl;

    }
}