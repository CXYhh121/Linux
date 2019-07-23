#ifndef __TCP_SEVER_HPP__
#define __TCP_SEVER_HPP__

#include <iostream>
#include <string>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <pthread.h>

class TcpServer;
class Arg{
    public:
        std::string ip;
        int port;
        int sock;
        TcpServer* tsp;
};

class TcpServer{
        private:
            int listen_sock;//套接字
            //std::string ip;
            int port;
        public:
            TcpServer(int port_)
                :port(port_)    //构造函数
                ,listen_sock(-1)
            {}
            void InitServer()//初始化
            {
                listen_sock = socket(AF_INET,SOCK_STREAM,0);
                if(listen_sock < 0){
                    std::cerr << "socket error" << std::endl;                                                             
                    exit(2);
                }                    


                //该接口是为了让服务器在退出之后能够迅速重新启动，即让端口可以复用
                int opt = 1;
                setsockopt(listen_sock,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));

                //使用ipv4协议相关的结构体
                struct sockaddr_in local;                                                                                
                bzero(&local,sizeof(local));//给结构体清零的函数
                local.sin_family = AF_INET;                                                             
                local.sin_port = htons(port);  
                //不用指定ip、地址，只要是给服务器指定的端口发送的连接，服务器均能接收
                local.sin_addr.s_addr = htonl(INADDR_ANY);
                //local.sin_addr.s_addr = inet_addr(ip.c_str());
                if(bind(listen_sock,(struct sockaddr*)&local,sizeof(local)) < 0)//绑定套接字  
                {                                                                                                
                    std::cerr << "bind error" << std::endl;
                    exit(3);  
                }          
                if(listen(listen_sock,5) < 0)//将套接字设置为监听状态                  
                {
                    std::cerr << "listen error" << std::endl;
                    exit(4);
                }
                signal(SIGCHLD,SIG_IGN);
            }
            void Service(int sock,std::string ip_,int port_)//对外提供服务
            {
                while(1){
                    char buf[1024];
                    ssize_t s = read(sock,buf,sizeof(buf)-1);
                    if(s > 0){
                        buf[s] = 0;//把最后一个字符设置为0                                          
                        std::cout <<"[" << ip_<<":"<<port_ << "]" << buf << std::endl;
                        write(sock,buf,strlen(buf));
                    }else if(s == 0){ //读到文件结尾，说明客户端退出了，不仅没有往套接字中写数据，还将套接字关闭了
                        std::cout << "client quit!" << std::endl;
                        break;
                    }else{
                        std::cerr << "read error" << std::endl;
                        break;
                    }
                }
                close(sock);
        }

        //线程启动后需要执行的函数    
        static void *HandlerRequest(void* arg)
        {
            //分离线程，让其执行自己的任务
            pthread_detach(pthread_self());
            Arg* sarg = (Arg*)arg;
            sarg->tsp->Service(sarg->sock,sarg->ip,sarg->port);
            delete sarg;
        }
            

        void Start()//启动
        {
            struct sockaddr_in peer;//存储建立连接的相关数据，端口号，IP地址
            socklen_t len;
            for(;;){
                len = sizeof(peer);
                int sock = accept(listen_sock,(struct sockaddr*)&peer,&len);//接受建立好的连接，并开始服务
                if(sock < 0){
                    std::cerr << "accept error" << std::endl;
                    continue;//失败可以接受，继续询问下一个
                }
                std::cout << "Get a new client " << sock << std::endl;
                //为了让服务器知道自己是在为哪个客户端服务，我们将客户端信息获取一下
                int port_ = ntohs(peer.sin_port);
                std::string ip_ = inet_ntoa(peer.sin_addr);

                //版本三，基于多线程的TCP服务器客户端

                pthread_t tid;
                Arg* arg = new Arg;
                arg->sock = sock;
                arg->ip = ip_;
                arg->port = port_;
                arg->tsp = this;
                pthread_create(&tid,NULL,HandlerRequest,(void*)arg);


                //由于服务器不可能只服务一个客户端，因此我们创建多进程，是服务器能够服务多个客户端
                // pid_t id = fork();
                // if(id < 0){
                //     std::cerr << "fork error" <<std::endl;
                //     close(sock);
                //     //to do other things;
                //     continue;
                // }else if(id == 0){//子进程创建成功，让子进程进行服务
                //     close(listen_sock);
                //     Service(sock,ip_,port_);//给建立好连接的客户端提供服务
                //     exit(0);
                // }else{//父进程继续干自己的accept工作
                //     //wait ? 父进程不等子进程，子进程退出资源无法回收，变成僵尸进程
                //     //父进程等子进程，阻塞等待时，若第一批接收的连接不退出则父进程无法接受其他客户端发起的连接
                //     //非阻塞等待的话，若再无客户端发起连接，父进程就会阻塞等待接收连接从而又造成子进程变成僵尸进程
                //     //这里使用我们直接讲信号提到的SIGCHLD信号，子进程不会默默退出，退出时会给父进程发送SIGCHLD信号
                //     //父进程只要忽略该信号，不进行处理，操作系统就会自动回收子进程的资源，不会造成僵尸进程
                //     //
                //     //clild
                //     close(sock);
                // }
            }
        }
        ~TcpServer()//析构函数
        {
            if(listen_sock > 0)
                close(listen_sock);
        }
};

#endif
