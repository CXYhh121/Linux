#define _CRT_SECURE_NO_WARNINGS

//�鿴һ������
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


//��ȡ�ӽ��̵�PID�͸����̵�PPID
//#include <stdio.h>
//#include <sys/types.h>
//#include <unistd.h>
//int main()
//{
//	printf("pid: %d\n", getpid());
//	printf("ppid: %d\n", getppid());
//	return 0;
//}


//fork()����
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

//ͨ���ж�fork()�����ķ���ֵ�жϸ��ӽ��̣��ö���ִ�в�ͬ������
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