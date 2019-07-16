#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int signo,siginfo_t* info,void* p)
{
    printf("signo =: %d\n",signo);
    printf("sender pid = :%d\n",info->si_code);//使用第二个参数打印出更多该信号的信息
}

int main()
{
    struct sigaction act,oact;
    act.sa_sigaction = handler;//更换成员，以该方法处理信号
    sigemptyset(&act.sa_mask);//这个函数后面介绍，是用来初始化sa_mask的
    act.sa_flags = SA_SIGINFO;//若不使用函数指针则将此项设置为0,此时我们配合sa_sigaction中的第二个成员使用
    sigaction(2,&act,&oact);//表示对信号标号为2的信号进行操作
    while(1){
        printf("i am a process....\n");
        sleep(1);
    }
    return 0;
}
