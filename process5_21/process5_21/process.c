#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <sys/types.h>
//#include <sys/wait.h>
//
//int main()
//{
//	pid_t pid;
//	pid = fork();
//	if (pid < 0){
//		printf("%s fork error\n", __FUNCTION__);
//		return 1;
//	}
//	else if (pid == 0){ //child
//		printf("child is run, pid is : %d\n", getpid());
//		sleep(5);
//		exit(257);
//	}
//	else{
//		int status = 0;
//		pid_t ret = waitpid(-1, &status, 0);//����ʽ�ȴ����ȴ�5S
//		printf("this is test for wait\n");
//		if (WIFEXITED(status) && ret == pid){
//			printf("wait child 5s success, child return code is :%d.\n", WEXITSTATUS(status));
//		}
//		else{
//			printf("wait child failed, return.\n");
//			return 1;
//		}
//	}
//	return 0;
//}//#include <stdio.h>
//#include <unistd.h>
//#include <stdlib.h>
//#include <sys/wait.h>
//int main()
//{
//	pid_t pid;
//
//	pid = fork();
//	if (pid < 0){
//		printf("%s fork error\n", __FUNCTION__);
//		return 1;
//	}
//	else if (pid == 0){ //child
//		printf("child is run, pid is : %d\n", getpid());
//		sleep(5);
//		exit(1);
//	}
//	else{
//		int status = 0;
//		pid_t ret = 0;
//		do
//		{
//			ret = waitpid(-1, &status, WNOHANG);//������ʽ�ȴ�
//			if (ret == 0){
//				printf("child is running\n");
//			}
//			sleep(1);
//		} while (ret == 0);
//
//		if (WIFEXITED(status) && ret == pid){
//			printf("wait child 5s success, child return code is :%d.\n", WEXITSTATUS(status));
//		}
//		else{
//			printf("wait child failed, return.\n");
//			return 1;
//		}
//	}
//	return 0;
//}//#include <unistd.h>
//int main()
//{
//	char *const argv[] = { "ps", "-ef", NULL };
//	char *const envp[] = { "PATH=/bin:/usr/bin", "TERM=console", NULL };
//	execl("/bin/ps", "ps", "-ef", NULL);
//	// ��p�ģ�����ʹ�û�������PATH������дȫ·��
//	execlp("ps", "ps", "-ef", NULL);
//	// ��e�ģ���Ҫ�Լ���װ��������
//	execle("ps", "ps", "-ef", NULL, envp);
//	execv("/bin/ps", argv);
//
//	// ��p�ģ�����ʹ�û�������PATH������дȫ·��
//	execvp("ps", argv);
//	// ��e�ģ���Ҫ�Լ���װ��������
//	execve("/bin/ps", argv, envp);
//	exit(0);
//}