#ifndef __SELECT_SERVER_HPP__
#define __SELECT_SERVER_HPP__
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string>

using namespace std;

class Sock{
    private:
        int listen_sock;
        string ip;
        int port;

    public:
        Sock(string &ip_,int &port_)
            :listen_sock(-1)
            ,ip(ip_)
            ,port(port_)
        {}

        int socket()
        {
            listen_sock = socket(AF_INET,SOCK_STREAM,0);
            if(listen_sock < 0){
                cerr << "Socket error" << endl;
                exit(2);
            }
            return 0;
        }

        bool Bind()
        {
            struct sockaddr_in local;
            local.sin_family = AF_INET;
            local.sin_port = htons(port);
            local.sin_addr.s_addr = inet_addr(ip.c_str());

            if(bind(listen_sock,(struct sockaddr*)local,sizeof(local)) < 0){
                cerr << "bind error" << endl;
                exit(3);
            }
            return true;
        }

        bool Listen()
        {
            if(listen(listen_sock,5) < 0){
                cerr << "listen error" << endl;
                exit(4);
            }
            return true;
        }

        int GetSock()
        {
            return listen_sock;
        }
        ~Sock()
        {
            if(listen_sock > 0)
            {
                close(listen_sock);
            }
        }
};


class SelectServer{

};


#endif
