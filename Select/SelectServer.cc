#include "SelectServer.hpp"

void Usage(int proc)
{
    cout << "Usage" << proc << "Server ip and Server port" << endl;
    cout << "Version 0.0.1" << endl;
}

//SelectServer ip port
int main(int argc,char* argv[])
{
    if(argc != 3){
        Usage(argv[0]);
        exit(1);
    }
    int port = (atoi)argv[2];
    string ip = argv[1];
    
    Sock listen_sock(ip,port);
    listen_sock.Socket();
    listen_sock.Bind();
    listen_sock.Listen();

    int max_fd = ?;
    for(;;){
        fd_set rfds;
        FD_ZERO(&rfds);
        FD_SET(listen_sock.GetSock(),&rfds);
        struct timeval timeout = {5,0};
        switch(select(max_fd + 1,&rfds,NULL,NULL,&timeout)){
            case 0:
                cout << "timeout...." << endl;
                break;
            case -1:
                cerr << "select error..." << endl;
            default://有事件就绪
                HandlerEvents();
                break;
    }
    return 0;
}
