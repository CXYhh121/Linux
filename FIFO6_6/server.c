#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#define ERR_EXIT(m)\
do{\
    perror(m);\
    exit(EXIT_FAILURE);\
}while(0)

int main()
{
    umask(0);
    if(mkfifo("myfifo",0644) < 0)//创建一个管道
    {
        ERR_EXIT("mkfifo\n");
    }

    int rfd = open("myfifo",O_RDONLY);//打开这个管道，返回值是文件描述符
    if(rfd < 0)
    {
        ERR_EXIT("open\n");
    }

    char buf[1024];
    while(1)
    {
        buf[0] = 0;
        printf("Please wait....\n");
        ssize_t s = read(rfd, buf, sizeof(buf)-1);
        if(s > 0)//若是read的返回值大于0说明读取成功
        {
            buf[s - 1] = 0;//为了去掉最后输入的回车
            printf("client say#: %s\n",buf);
        }else if(s == 0){//所读文件已经关闭，即client进程退出了
            printf("client quit,exit now!\n");
            exit(EXIT_SUCCESS);
        }else{
            ERR_EXIT("read error\n");
        }
    }
    close(rfd);
    return 0;
}
