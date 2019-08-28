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

class SelectServer{
    public:
        int port;
        int listen_sock;
        std::vector<int> rfdv;//存放要关注文件描述符的数组
        int cap;//select能关注最大文件描述符的数量
    public:
        SelectServer(int port_ = 8080):port(port_),listen_sock(-1),rfdv(1024,-1)
        {
            cap = 1024;//计算方式是sizeof(fd_set)*8
        }
        void ServerInit()
        {
            listen_sock = SockApi::Socket();//一些熟悉的socket函数调用
            SockApi::Bind(listen_sock, port);
            SockApi::Listen(listen_sock);
        }
        void Run()
        {
            rfdv[0] = listen_sock;
            //监听描述符一定要设置进数组中，笔者因为开始忘记设置出了1w个bug，都是泪
            for(;;){
                fd_set rfds;//读文件描述符集合
                FD_ZERO(&rfds);//初始化
                int max_fd = listen_sock;//记录最大的文件描述值，为设置nfds做铺垫
                rfdv[0] = listen_sock;//一定记住这一步
                for(int i = 0; i < cap; i++){
                    if(rfdv[i] == -1){//为-1表示这个位置没有有效的文件描述符
                        continue;
                    }
                    if(max_fd < rfdv[i]){
                        max_fd = rfdv[i];//更新max_fd
                    }
                    FD_SET(rfdv[i], &rfds);//设置进位图
                }
                struct timeval timeout = {5, 0};//将timeout时间设置为5s
                switch(select(max_fd+1, &rfds, nullptr, nullptr, nullptr)){
                    case 0:
                        cout << "timeout ... " <<endl;
                        break;
                    case -1:
                        cout << "select error ..." <<endl;
                        break;
                    default:
                        cout << "handler start ..." <<endl;
                        Handler(&rfds);//已经有文件描述符读事件就绪
                        cout << "handler end ..." <<endl;
                        break;
                }
            }
        }
        void Handler(fd_set* rfds)
        {
            for(int i = 0;i < cap; i++)
            {
                if(rfdv[i] == -1){//为-1跳过
                    continue;
                }

                if(i == 0 && FD_ISSET(rfdv[i],rfds)){
                    int fd = SockApi::Accept(listen_sock);
                    //走到这里说明就绪的读事件是有新的连接，新连接在select中也是读事件
                    int j;
                    for(j = 1; j < cap; j++){
                        if(rfdv[j] == -1){
                            cout << "get a new connect ..." <<endl;
                            rfdv[j] = fd;
                            //将这个fd放入数组中，下次设置这个fd
                            break;//一定要break，不然就循环设置满数组最后溢出
                        }
                        if(j == cap){//此时说明关注的文件描述符超过了1024，设置失败
                            cout << "rfdv is full ..." <<endl;
                            close(fd);
                            break;
                        }
                    }
                }
                else if(i != 0 && FD_ISSET(rfdv[i], rfds))//其他文件读事件就绪
                {
                    char buf[1024];
                    ssize_t s = read(rfdv[i], buf, sizeof(buf) - 1);
                    if(s > 0){//这里其实这样读会有粘包问题，但是我们关注点不在这
                        fflush(stdout);
                        cout << buf <<endl;
                    }
                    else if(s == 0){
                        cout << "clinet quit" <<endl;
                        //这里很关键，读到0说明对端把连接关了，所以文件描述符不需要在关心
                        close(rfdv[i]);
                        rfdv[i] = -1;
                    }
                    else{
                        close(rfdv[i]);
                        //读出错我们使用和对端关闭一样的处理方式
                        rfdv[i] = -1;
                        cout << "read error" <<endl;
                    }
                }
            }
        }
        ~SelectServer()
        {}
};

