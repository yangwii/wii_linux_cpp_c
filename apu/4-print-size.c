#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("no filepah\n");
		return 1;
	}

	char *filepaht = argv[1];
	struct stat file;
	if(lstat(filepaht, &file) == -1)
	{
		printf("get file info fail\n");
		return 2;
	}
	if(S_ISREG(file.st_mode) || S_ISLNK(file.st_mode))
	{
		printf("size of file is %lld byte\n", (long long)file.st_size);
	}
	else
	{
		printf("file is not regular file\n");
	}
	return 0;
}
