#include "pollServer.hpp"


int main()
{
    PollServer ps;
    volatile bool quit = false;
    while(!quit)
    {
        ps->ServerInit();
        ps->Run();
    }

    return 0;
}
