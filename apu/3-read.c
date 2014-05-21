#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>

int main(void)
{
	char filename[] = "test-3-write.txt";
	int flag = O_RDWR | O_CREAT;
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	int fd;
	if((fd = open(filename, flag, mode)) == -1)
	{
		printf("open/create file fail\n");
		printf("errno=%d\n", errno);
		return 1;
	}
	char buf[12];
	if(read(fd, buf, 12) != 12)
	{
		printf("read file failed\n");
	}
	printf("txt-->%s\n", buf);
	return 0;
}
