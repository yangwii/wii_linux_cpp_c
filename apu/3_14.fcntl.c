#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
	int val;
	if(argc != 2)
	{
		printf("argc error\n");
		exit(-1);
	}
	if((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
	{
		printf("fcntl error\n");
		exit(-2);
	}

	switch(val & O_ACCMODE)
	{
		case O_RDONLY:
			printf("READ ONLY\n");
			break;
		case O_WRONLY:
			printf("WRITE ONLY\n");
			break;
		case O_RDWR:
			printf("READ WRITE\n");
			break;

		default:
			printf("unknown access mode\n");
	}

	if(val & O_APPEND)
	{
		printf("APPEND\n");
	}

	exit(0);
}
