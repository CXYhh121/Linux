#define _CRT_SECURE_NO_WARNINGS

//查看一个进程
//#include <stdio.h>
//#include <sys/types.h>
//#include <unistd.h>
//int main()
//{
//	while (1){
//		sleep(1);
//	}
//	return 0;
//}


//获取子进程的PID和父进程的PPID
//#include <stdio.h>
//#include <sys/types.h>
//#include <unistd.h>
//int main()
//{
//	printf("pid: %d\n", getpid());
//	printf("ppid: %d\n", getppid());
//	return 0;
//}


//fork()函数
//#include <stdio.h>
//#include <sys/types.h>
//#include <unistd.h>
//int main()
//{
//	int ret = fork();
//	printf("hello proc : %d!, ret: %d\n", getpid(), ret);
//	sleep(1);
//	return 0;
//}

//通过判断fork()函数的返回值判断父子进程，让二者执行不同的任务
//#include <stdio.h>
//#include <sys/types.h>
//#include <unistd.h>
//int main()
//{
//	int ret = fork();
//	if (ret < 0){
//		perror("fork");
//		return 1;
//	}
//	else if (ret == 0){ //child
//		printf("I am child : %d!, ret: %d\n", getpid(), ret);
//	}
//	else{ //father
//		printf("I am father : %d!, ret: %d\n", getpid(), ret);
//	}
//	sleep(1);
//	return 0;
//}