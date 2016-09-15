#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

const int BUFFERSIZE = 10;

typedef struct FdList
{
	int fd;
	struct FdList *next;
}FdList;

int my_dup2(int fd1, int fd2)
{
	if(fd2 < 0 || fd2 > 256)
	{
		printf("Descriptor you input is unvalid (0 < descriptor < 256).\n");
		return -1;
	}
	if(fd1 == fd2)
		return fd1;
	close(fd2);
	FdList *h = NULL, *p;
	int new_fd;
	while((new_fd = dup(fd1)) != fd2)
	{
		p = (FdList *)malloc(sizeof(FdList));
		p->fd = new_fd;
		p->next = h;
		h = p;
	}

	while(h)
	{
		close(h->fd);
		p = h;
		h = h->next;
		free(p);
	}
	return new_fd;
}

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("Usage: ./a.out filepath\n");
		exit(0);
	}
	int fd1;
	if((fd1 = open(argv[1], O_RDONLY)) == -1)
	{
		printf("Open file %s failed.\n", argv[0]);
		exit(0);
	}
	printf("descriptor: %d\n", fd1);
	printf("Please input the file descriptor that you want to set: ");
	int fd2;
	scanf("%d", &fd2);
	if(my_dup2(fd1, fd2) < -1)
	{
		printf("dup2 function failed to get the descriptor %d\n", fd2);
		exit(0);
	}

	char buf[BUFFERSIZE+1];
	if(read(fd2, buf, BUFFERSIZE) < -1)
	{
		printf("Failed to read the file.\n");
		exit(0);
	}
	buf[BUFFERSIZE] = '\0';
	printf("output: %s\n", buf);
	exit(1);
}