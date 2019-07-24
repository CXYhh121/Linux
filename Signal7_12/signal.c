#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler(int signum)
{
    printf("catch signal is signum:%d\n",signum);
}
int main()
{
    signal(2,handler);
    while(1)
    {
        printf("i am a process...!\n");
        sleep(1);
    }
    return 0;
}
