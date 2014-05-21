#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	char filename[] = "test-3-create.txt";
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	if(creat(filename, mode) == -1)
	{
		printf("create file fail\n");
		return 1;
	}
	printf("create file OK\n");
	return 0;
}
