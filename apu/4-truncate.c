#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		printf("argv error!!\n");
		return 1;
	}

	char *filepath = argv[1];
	long long int new_size = atoll(argv[2]);
	
	struct stat file;
	if(stat(filepath, &file) == -1)
	{
		printf("get file info failed\n");
		return 2;
	}
	printf("size of file is %lld byte\n", (long long)file.st_size);

	if(truncate(filepath, new_size) == -1)
	{
		printf("truncate file error\n");
		return 3;
	}
	if(stat(filepath, &file) == -1)
	{
		printf("get file info failed\n");
		return 2;
	}
	printf("size of file is %lld byte\n", (long long)file.st_size);
	return 0;
}
