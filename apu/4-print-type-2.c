#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("usage:./a.out filepath\n");
		return 1;
	}
	char *filepath = argv[1];
	struct stat file;
	if(stat(filepath, &file) == -1)
	{
		printf("get file %s fail\n", filepath);
		return 2;
	}
		
	switch(file.st_mode & S_IFMT)
	{
		case S_IFREG:
				printf("regular\n");
				break;
		case S_IFDIR:
				printf("dir\n");
				break;
		case S_IFCHR:
				printf("char device\n");
				break;
		case S_IFBLK:
				printf("BLOCK device\n");
				break;
		case S_IFIFO:
				printf("FIFO\n");
				break;
		case S_IFLNK:
				printf("symlolink link\n");
				break;
		case S_IFSOCK:
				printf("SOCKET\n");
				break;
		default:
				printf("unknow type\n");
	}
	return 0;
}
