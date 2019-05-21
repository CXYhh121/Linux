#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
{
	pid_t pid;
	pid = fork();
	if (pid < 0){
		printf("%s fork error\n", __FUNCTION__);
		return 1;
	}else if (pid == 0){ //child
		printf("child is run, pid is : %d\n", getpid());
		sleep(5);
		exit(1);
		}else{
			int status = 0;
			pid_t ret = 0;
			do{
				ret = waitpid(-1, &status, WNOHANG);//非阻塞式等待
				if (ret == 0){
					printf("father is running....\n");
				}
				sleep(1);
			} while (ret == 0);
			if (WIFEXITED(status) && ret == pid){
				printf("wait child 5s success, child return code is :%d.\n", WEXITSTATUS(status));
			}
			else{
				printf("wait child failed, return.\n");
			}
		}
	return 0;
}
