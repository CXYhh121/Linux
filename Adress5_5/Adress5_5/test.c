#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <unistd.h>
//#include <stdlib.h>
//int g_val = 0;
//int main()
//{
//	pid_t id = fork();
//	if (id < 0){
//		perror("fork");
//		return 0;
//	}
//	else if (id == 0){ //child printf("child[%d]: %d : %p\n", getpid(), g_val, &g_val);
//	}
//	else{ //parent
//		printf("parent[%d]: %d : %p\n", getpid(), g_val, &g_val);
//	}
//	sleep(1);
//	return 0;
//}//#include <stdio.h>
//#include <unistd.h>
//#include <stdlib.h>
//int g_val = 0;
//int main()
//{
//	pid_t id = fork();
//	if (id < 0){
//		perror("fork");
//		return 0;
//	}
//	else if (id == 0){ //child,子进程肯定先跑完，也就是子进程先修改，完成之后，父进程再读取
//		g_val = 100;
//		printf("child[%d]: %d : %p\n", getpid(), g_val, &g_val);
//	}
//	else{ //parent
//		sleep(3);
//		printf("parent[%d]: %d : %p\n", getpid(), g_val, &g_val);
//	}
//	sleep(1);
//	return 0;
//}
////与环境相关，观察现象即可
//child[3046]: 100 : 0x80497e8
//parent[3045] : 0 : 0x80497e8
