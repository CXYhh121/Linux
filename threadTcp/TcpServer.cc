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

    int port = atoi(argv[1]);
    TcpServer* tsp = new TcpServer(port);
    tsp->InitServer();
    tsp->Start();
    return 0;
}
