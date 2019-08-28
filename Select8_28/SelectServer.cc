#include "SelectServer.hpp"


int main()
{
    volatile bool quit = false;
    SelectServer* ss = new SelectServer();
    while(!quit)
    {
        ss->ServerInit();
        ss->Run();
    }

    return 0;

}
