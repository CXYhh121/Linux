#include "TcpServer.hpp"

//./TcpServer ip port
//

void Usage(std::string proc)
{
    std::cout << "Usage: " << proc << "IP PORT" << std::endl;
    std::cout << "Version 0.0.1" << std::endl;
}


int main(int argc,char* argv[])
{
    if(argc != 3){
        Usage(argv[0]);
        exit(1);
    }

    int port = atoi(argv[2]);
    std::string ip = argv[1];
    TcpServer* tsp = new TcpServer(ip,port);
    tsp->InitServer();
    tsp->Start();
    return 0;
}
