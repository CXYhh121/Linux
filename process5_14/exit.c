#include <stdio.h>
#include <unistd.h>

void exit(int status);

int main()
{
	printf("hello world!\n");
	exit(100);
}

//void _exit(int status);

//int main()
//{
//	printf("hello world!");
//	_exit(0);
//}
