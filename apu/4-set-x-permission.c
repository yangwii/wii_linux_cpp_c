#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		fprintf(stderr, "usage:./a.out filepath\n");
		return 1;
	}

	char *filepath = argv[1];
	struct stat file;
	if(stat(filepath, &file) == -1)
	{
		perror("get file info fail\n");
		return 2;
	}

	if(chmod(filepath,  S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH ) == -1)
	{
		perror("set x permission fail\n");
		return 3;
	}
	return 0;
}
