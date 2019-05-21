#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
	pid_t id = fork();
	if(id == 0)
	{//child
		printf("I am a child.....\n");
		sleep(10);
		exit(123);
	}
	else{//father
		printf("I am a father....\n");
		wait(NULL);
	}

	return 0;
}
