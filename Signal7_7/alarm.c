#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    int count = 1;
    alarm(1);
    for(;1;count++){
        printf("count = %d\n",count);
    }
    return 0;
}

