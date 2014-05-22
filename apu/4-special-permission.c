#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

void print_set_or_not(char *bit_name, int is_set);

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		fprintf(stderr, "usage:./a.out filename\n");
		return 1;
	}

	char *filename = argv[1];
	struct stat file;
	int fd = open(filename, O_RDONLY);
	if(fd == -1)
	{
		printf("open file fail\n");
		return 4;
	}
	if(fstat(fd, &file) == -1)
	{
		perror("get file info fail\n");
		return 2;
	}

	if(S_ISREG(file.st_mode))
	{
		print_set_or_not("set-user-id", file.st_mode & S_ISUID == S_ISUID);
		print_set_or_not("set-group-id", file.st_mode & S_ISGID == S_ISGID);
	}

	if(S_ISDIR(file.st_mode))
	{
		print_set_or_not("sticky", file.st_mode & S_ISVTX == S_ISVTX);
	}
	return 0;
}
void print_set_or_not(char *bit_name, int is_set)
{
	printf("%s bit is", bit_name);
	if(is_set)
	{
		printf("set");
	}
	else
	{
		printf("not set");
	}

	printf("\n");
}
