#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

#define NUM 32

int main()
{
	char buff[1024] = {0};
	string tips = "[CXY@localhost XXX]# ";//仿造一个命令行解释器提示符
	cout << tips;
	fgets(buff, sizeof(buff)-1, stdin);//从键盘中获取用户输入的信息，不能用cin，因为会有空格
	buff[strlen(buff) - 1] = 0;

	//ls -a -l -o -i
	char *argv[NUM];//为使用替换函数execvp，创建该数组以传递命令
	argv[0] = strtok(buff," ");//字符串分隔函数，将每个命令分隔
	int i = 0;
	while(argv[i] != NULL){
		i++;
		argv[i] = strtok(NULL," ");
	}
	pid_t id = fork();
	if(id == 0){//child
		cout << "child running...." << endl;
		execvp(argv[0],argv);
		exit(123);
	}else{//father
		int status = 0;
		waitpid(id, &status, 0);//创建子进程去执行相关命令，父进程只要等就行了
		cout << "Exit Code: "<< WEXITSTATUS(status) << endl;
	}
	return 0;
}
