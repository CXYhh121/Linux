#pragma once
#include<iostream>
#include<sys/select.h>
#include<sys/stat.h>
#include<unistd.h>
#include<vector>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<strings.h>
#include<stdio.h>
using namespace std;

class SockApi{//将socket类使用一个类单独封装，在select服务器中直接调用
    public:
        static int Socket()
        {
            int sock = socket(AF_INET,SOCK_STREAM,0);
            if(sock < 0){
                exit(2);
            }
            int opt = 1;
            setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
            return sock;
        }
        static void Bind(int sock, int port)
        {
            struct sockaddr_in local;
            bzero(&local, sizeof(local));
            local.sin_family = AF_INET;
            local.sin_port = htons(port);
            local.sin_addr.s_addr = htonl(INADDR_ANY);

            if(bind(sock, (sockaddr*)&local, sizeof(local)) < 0){
                exit(3);
            }
        }
        static void Listen(int sock)
        {
            if(listen(sock, 5) < 0){
                exit(4);
            }
        }
        static int Accept(int listen_sock)
        {
            struct sockaddr_in peer;
            socklen_t len = sizeof(peer);
            int sock = accept(listen_sock, (sockaddr*)&peer, &len);
            if(sock < 0){
                return -1;
            }
            return sock;
        }
};

class PollServer{
    private:
        int port;
        int listen_sock;
        std::vector<int> rfdv;
        
    public:
        PollServer(int _port = 8080)
            :port(_port)
            ,listen_sock(-1)
            ,rfdv(1024,-1)
        {

        }

        void ServerInit()
        {
            listen_sock = SockApi::Socket();
            SockApi::Bind(listen_sock,port);
            SockApi::Listen(listen_sock);
        }
        
        void Run()
        {

        }

        ~PollServer()
        {

        }

};
