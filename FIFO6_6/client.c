#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define ERR_EXIT(m)\
do{\
    perror(m);\
    exit(EXIT_FAILURE);\
}while(0)

int main()
{
    int wfd = open("myfifo",O_WRONLY);//以写方式打开这个管道，返回值是文件描述符
    if(wfd < 0)
    {
        ERR_EXIT("open");
    }

    char buf[1024];
    while(1)
    {
        buf[0] = 0;
        printf("Please Enter#: ");
        fflush(stdout);
        ssize_t s = read(0,buf,sizeof(buf)-1);

        if(s > 0)//若是read的返回值大于0说明读取成功
        {
            buf[s] = 0;//给字符串后加上\0
            write(wfd,buf,strlen(buf));
        }else if(s <= 0)
        {
            ERR_EXIT("read");
        }
    }
    close(wfd);
    return 0;
}
