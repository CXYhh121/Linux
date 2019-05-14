#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t pid = fork();
	if(pid < 0)
	{
		perror("fork()\n");
			return -1;
	}
	else if(pid == 0)
	{//child
		printf("child:pid = %d,ppid = %d\n",getpid(),getppid());
		sleep(5);
	}
	else
	{//father
		printf("parent:pid = %d,ppid = %d\n",getpid(),getppid());
	}

	return 0;
}
