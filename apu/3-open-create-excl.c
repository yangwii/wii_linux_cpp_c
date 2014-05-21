#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>

int main(void)
{
	char filename[] = "test-3-open-create.txt";
	int flag = O_RDWR | O_CREAT | O_EXCL;
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	if(open(filename, flag, mode) == -1)
	{
		if(errno == EEXIST)
		{
			printf("file exists\n");
		}
		else
		{
			printf("open/create file fail\n");
			printf("errno=%d\n", errno);
		}
		return 1;
	}
	return 0;
}
