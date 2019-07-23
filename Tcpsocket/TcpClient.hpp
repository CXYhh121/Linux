#ifndef __TCP_CLIENT_HPP__
#define __TCP_CLIENT_HPP__
#include <iostream>
#include <string>
#include <strings.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>

class TcpClient{
        private:
             int sock;
             std::string ip;
             int port;
        public:
             TcpClient(std::string ip_,int port_)
                 :ip(ip_)
                 ,port(port_)
                  ,sock(-1)
             {}
             void InitClient()
             {
                 sock = socket(AF_INET,SOCK_STREAM,0);//创建套接字
                 if(sock < 0){
                     std::cerr << "socket error" << std::endl;
                     exit(2); 
                 }
             }
             void Start()
             {
                 struct sockaddr_in peer;//该结构体存储与谁建立连接的数据
                 bzero(&peer,sizeof(peer));//将结构体清零
                 peer.sin_family = AF_INET;
                 peer.sin_port = htons(port);//端口号因为要跨网络，因此需要使用htons函数将本地端口号转换为网络字节序列的端口号
                 peer.sin_addr.s_addr = inet_addr(ip.c_str());//IP地址转换的函数，同样也需要跨网络传输
                 //与服务器建立连接的接口connect 
                 if(connect(sock,(struct sockaddr*)&peer,sizeof(peer)) < 0){
                     std::cerr << "connect error" << std::endl;
                     exit(3);
                 } 
                 //连接建立成功，开始向服务器发送请求(读写请求)  
                 char buf[1024];                                  
                 std::string in;                                                                                        
                 while(1){
                     std::cout << "Please Enter# ";      
                     std::cin >> in;
                     write(sock,in.c_str(),in.size());      
                     ssize_t s = read(sock,buf,sizeof(buf));
                     if(s > 0){
                         buf[s] = 0;
                         std::cout << "Server Echo# " << buf << std::endl;
                     }else if(s == 0){
                         std::cout << "Server not have message " << std::endl;
                     }else{
                         std::cerr << "read error" << std::endl;
                         exit(4);
                     }
                 }
                            
             }
             ~TcpClient()
             {
                 if(sock > 0)
                     close(sock);
             }
                                
};                       

#endif
