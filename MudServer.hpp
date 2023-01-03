#ifndef MUD_SERVER_H_
#define MUD_SERVER_H_

extern "C" {
    #include <netinet/in.h>
}

#define SERVER_BACKLOG 5

class MudServer {
    private:
        int _portNum;
        int _serverFD;
        bool _mudRunning = true;
        sockaddr_in _addressStruct;
        void setServerFD();
        void setAddress();
        void bindAddress();
        void serverListen();
    public:
        MudServer(int portNum);
        int getPort();
        void setPort(int newPort);
        int getServerFD();
        void reuseAddress();
        void runGame();
};

#endif
