#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t id;
	printf("before:pid is %d\n", getpid());
	
	id = fork();
	
	if(id < 0)
	{
		perror("fork()");
	}


	printf("After:pid is %d, fork return %d\n", getpid(), id);
	sleep(1);
	return 0;
}
