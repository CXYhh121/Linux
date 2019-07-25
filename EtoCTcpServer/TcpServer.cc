#include "TcpServer.hpp"

//./TcpServer port
//

void Usage(std::string proc)
{
    std::cout << "Usage: " << proc << "PORT" << std::endl;
    std::cout << "Version 0.0.1" << std::endl;
}


int main(int argc,char* argv[])
{
    if(argc != 2){
        Usage(argv[0]);
        exit(1);
    }


    dict.insert(std::pair<std::string,std::string>("apple","苹果"));
    dict.insert(std::pair<std::string,std::string>("banana","香蕉"));
    dict.insert(std::pair<std::string,std::string>("orange","橘子"));
    dict.insert(std::pair<std::string,std::string>("peach","桃子"));
    dict.insert(std::pair<std::string,std::string>("lemon","柠檬"));

    int port = atoi(argv[1]);
    TcpServer* tsp = new TcpServer(port);
    tsp->InitServer();
    tsp->Start();
    return 0;
}
