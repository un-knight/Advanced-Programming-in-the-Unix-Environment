// date:15/9/2016
// author:un-knight
// at MIT license

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

const int BUF = 1024;

int main(int argc, char **argv)
{
	int fd;
	off_t currpos;
	// 打开文件
	if((fd = open("testfile", O_RDWR | O_APPEND)) == -1)
	{
		printf("open file failed.\n");
		exit(0);
	}

	// 获取并输出当前文件偏移量
	if((currpos = lseek(fd, 0, SEEK_CUR)) < -1)
	{
		printf("lseek failed.\n");
		exit(0);
	}
	printf("currpos:%ld\n", currpos);

	// 设置文件偏移量
	if((currpos = lseek(fd, 5, SEEK_SET)) < -1)
	{
		printf("lseek failed.\n");
		exit(0);
	}
	printf("currpos:%ld\n", currpos);

	// 读取并输出指定偏移量位置的指定字节数长度的字符串
	char buf[BUF];
	if(read(fd, buf, 10) < -1)
	{
		printf("read failed.\n");
		exit(0);
	}
	buf[10] = '\0';
	printf("read: %s\n", buf);

	// 获取并输出当前文件位移量
	if((currpos = lseek(fd, 0, SEEK_CUR)) < -1)
	{
		printf("lseek failed.\n");
		exit(0);
	}
	printf("currpos:%ld\n", currpos);

	// 写数据
	if(write(fd, "Hello world.", 12) < -1)
	{
		printf("write failed.\n");
		exit(0);
	}

	// 获取并输出当前文件位移量
	if((currpos = lseek(fd, 0, SEEK_CUR)) < -1)
	{
		printf("lseek failed.\n");
		exit(0);
	}
	printf("currpos:%ld\n", currpos);
	exit(1);
}
