extern "C" {
    #include <sys/socket.h>
}

#include <cstdlib>
#include <cstdio>
#include "MudServer.hpp"
#include <iostream>

int MudServer::getPort() {
    return _portNum;
}

void MudServer::setPort(int newPort) {
    _portNum = newPort;
}

int MudServer::getServerFD() {
    return _serverFD;
}

MudServer::MudServer(int portNum) {
    setPort(portNum);
    setServerFD();
    setAddress();
}

void MudServer::setServerFD() {
    int serverFD;
    if ((serverFD = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("server socket");
        exit(1);
    }
    std::cout << "MudServer::setServerFD(): " << serverFD << std::endl;
    _serverFD = serverFD;
}

void MudServer::reuseAddress() {
    int x;
    if (setsockopt(_serverFD, SOL_SOCKET, SO_REUSEADDR, (char *) &x, sizeof(x)) < 0) {
        perror("reuse address");
        exit(1);
    }
}

void MudServer::setAddress() {
    _addressStruct.sin_family = AF_INET;
    _addressStruct.sin_port = htons(_portNum);
}

void MudServer::bindAddress() {
    if (bind(_serverFD, (struct sockaddr *) &_addressStruct, sizeof(_addressStruct)) < 0) {
        perror("MudServer::bindAddress()");
        exit(1);
    }
}

void MudServer::serverListen() {
    if (listen(_serverFD, SERVER_BACKLOG) < 0) {
        perror("Mudserver::serverListen()");
        exit(1);
    }
}

void MudServer::runGame() {
    while (_mudRunning) {
        
    }
}
