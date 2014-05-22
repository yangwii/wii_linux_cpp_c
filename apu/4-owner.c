#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("usage:./a/out filename\n");
		return 1;
	}

	struct stat file;
	char *filepath = argv[1];
	if(stat(filepath, &file) == -1)
	{
		printf("get file %s info fail\n", filepath);
		return 2;
	}

	printf("file owner uid = %u, gid = %u\n", file.st_uid, file.st_gid);

	return 0;
}
