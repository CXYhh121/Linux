#define _CRT_SECURE_NO_WARNINGS


//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	FILE *fp = fopen("myfile", "w");
//	if (!fp){
//		printf("fopen error!\n");
//	}
//	const char *msg = "hello world!\n";
//	int count = 5;
//	while (count--){
//		fwrite(msg, strlen(msg), 1, fp);
//	}
//	fclose(fp);
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	FILE *fp = fopen("myfile", "r");
//	if (!fp){
//		printf("fopen error!\n");
//	}
//	char buf[1024];
//	const char *msg = "hello world!\n";
//	while (1){
//		//注意返回值和参数，此处有坑，仔细查看man手册关于该函数的说明
//		ssize_t s = fread(buf, 1, strlen(msg), fp);
//		if (s > 0){
//			buf[s] = 0;
//			printf("%s", buf);
//		}
//		if (feof(fp)){
//			break;
//		}
//	}
//	fclose(fp);
//	return 0;
//}


//#include <stdio.h>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <fcntl.h>
//#include <unistd.h>
//#include <string.h>
//int main()
//{
//	int fd = open("myfile", O_RDONLY);
//	if (fd < 0){
//		perror("open");
//		return 1;
//	}
//	const char *msg = "hello bit!\n";
//	char buf[1024];
//	while (1){
//		ssize_t s = read(fd, buf, strlen(msg));//类比write
//		if (s > 0){
//			printf("%s", buf);
//		}
//		else{
//			break;
//		}
//	}
//	close(fd);
//	return 0;
//}//#include <stdio.h>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <fcntl.h>
//#include <unistd.h>
//#include <string.h>
//int main()
//{
//	umask(0);
//	int fd = open("myfile", O_WRONLY | O_CREAT, 0644);
//	if (fd < 0){
//		perror("open");
//		return 1;
//	}
//	int count = 5;
//	const char *msg = "hello bit!\n";
//	int len = strlen(msg);
//	while (count--){
//		write(fd, msg, len);//fd: 后面讲， msg：缓冲区首地址， len: 本次读取，期望写入多少个字节的数
//		//据。 返回值：实际写了多少字节数据
//	}
//	close(fd);
//	return 0;
//}//#include <stdio.h>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <fcntl.h>
//#include <string.h>
//int main()
//{
//	char buf[1024];
//	ssize_t s = read(0, buf, sizeof(buf));
//	if (s > 0){
//		buf[s] = 0;
//		write(1, buf, strlen(buf));
//		write(2, buf, strlen(buf));
//	}
//	return 0;
//}////#include <stdio.h>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <fcntl.h>
//int main()
//{
//	int fd = open("myfile", O_RDONLY);
//	if (fd < 0){
//		perror("open");
//		return 1;
//	}
//	printf("fd: %d\n", fd);
//	close(fd);
//	return 0;
//}


//#include <stdio.h>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <fcntl.h>
//int main()
//{
//	close(0);
//	//close(2);
//	int fd = open("myfile", O_RDONLY);
//	if (fd < 0){
//		perror("open");
//		return 1;
//	}
//	printf("fd: %d\n", fd);
//	close(fd);
//	return 0;
//}


//#include <stdio.h>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <fcntl.h>
//#include <stdlib.h>
//int main()
//{
//	close(1);
//	int fd = open("myfile", O_WRONLY | O_CREAT, 00644);
//	if (fd < 0){
//		perror("open");
//		return 1;
//	}
//	printf("fd: %d\n", fd);
//	fflush(stdout);
//
//	close(fd);
//	exit(0);
//}////#include <stdio.h>////int main()//{//	int m = 0123, n = 123;//	printf("%o %o\n", m,n);//	return 0;//}