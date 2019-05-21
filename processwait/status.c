#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
	pid_t id;
	if(id == 0)
	{//child
		printf("child : pid:%d,ppid :%d\n",getpid(),getppid());
		sleep(5);
		exit(13);//让子进程退出
	}
	else
	{//father
		printf("father :pid:%d,ppid :%d\n",getpid(),getppid());
        int status = 0;
		sleep(10);
		while(1){
			int ret = waitpid(id,&status,0);//阻塞式等待
			if(ret < 0){
				printf("wait error,wait ret:%d\n",ret);
			}else
			{
				printf("wait success....: %d\n",ret);
				printf("exit status:    : %d\n",(&status >> 8)&0xFF);
				printf("exit signal:    : %d\n",&status & 0x7F);
			}
		}
		sleep(5);
	return 0;
}
