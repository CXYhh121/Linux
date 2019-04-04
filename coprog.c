#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define PRINT_FONT_BLA  printf("\033[30m"); //黑色
#define PRINT_FONT_RED  printf("\033[31m"); //红色
#define PRINT_FONT_GRE  printf("\033[32m"); //绿色
#define PRINT_FONT_YEL  printf("\033[33m"); //黄色
#define PRINT_FONT_BLU  printf("\033[34m"); //蓝色
int main()
{
	int i = 0;
	char bar[102];
	const char* lable = "|/-\\";//由于\是特殊字符所以需要用\转义
	memset(bar,0,sizeof(bar)*sizeof(char));

	while(i <= 20)
	{
		PRINT_FONT_RED
		printf("[%-100s][%d%%][%c]\r", bar, i, lable[i%4]);
		fflush(stdout);
		bar[i++] = '#';
		usleep(100000);
	}
	
	while(i <= 40)
	{
		PRINT_FONT_YEL
		printf("[%-100s][%d%%][%c]\r", bar, i, lable[i%4]);
		fflush(stdout);
		bar[i++] = '#';
		usleep(100000);
	}

	while(i <= 60)
	{
		PRINT_FONT_BLU
		printf("[%-100s][%d%%][%c]\r", bar, i, lable[i%4]);
		fflush(stdout);
		bar[i++] = '#';
		usleep(100000);
	}
	while(i <= 100)
	{
		PRINT_FONT_GRE
		printf("[%-100s][%d%%][%c]\r", bar, i, lable[i%4]);
		fflush(stdout);
		bar[i++] = '#';
		usleep(100000);
	}
	PRINT_FONT_BLA
	printf("\n");
	return 0;
}

