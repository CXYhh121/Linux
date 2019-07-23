#include "TcpClient.hpp"

//./TcpClient ip port
//

void Usage(std::string proc)
{
    std::cout << "Usage: " << proc << "SERVER_IP SERVER_PORT" << std::endl;
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
    TcpClient* cli = new TcpClient(ip,port);
    cli->InitClient();
    cli->Start();
    return 0;
}
