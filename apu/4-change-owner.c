#include <unistd.h>
#include <stdio.h>

#define ROOT_UID 0
#define ROOT_GID 0
#define yangace_uid 1000
#define yangace_gid 1000
int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("usage:./a.out filepath\n");
		return 1;
	}

	char *filepath = argv[1];
	if(chown(filepath, yangace_uid, yangace_gid) == -1)
	{
		perror("change file owner fail\n");
		return 2;
	}
	return 0;
}
