#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	char filename[] = "test-3-close.txt";
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	int fd = creat(filename, mode);
	if(fd == -1)
	{
		printf("create file fail\n");
		return 1;
	}
	else
	{
		printf("create file ok\n");
	}

	if(close(fd) == -1)
	{
		printf("close file fail\n");
		return 2;
	}
	else
	{
		printf("close file ok\n");
	}
	return 0;
}
