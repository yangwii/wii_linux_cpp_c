#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>

#define FIRST_CONTENT "hello world"
#define SECOND_CONTENT "ABCDEFG"
#define LEN  sizeof(CONTENT)
#define HOLE_LENGTH 256

int main(void)
{
	char filename[] = "test-3-hole.txt";
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	int fd = creat(filename, mode);
	if(fd == -1)
	{
		printf("creat file failed\n");
		return 1;
	}

	if(write(fd, FIRST_CONTENT, sizeof(FIRST_CONTENT)) != sizeof(FIRST_CONTENT))
	{
		printf("write 1 file fail\n");
		return 2;
	}

	lseek(fd, HOLE_LENGTH, SEEK_CUR);
	if(write(fd, SECOND_CONTENT, sizeof(SECOND_CONTENT)) != sizeof(SECOND_CONTENT))
	{
		printf("write 2 file fail\n");
		return 3;
	}
	return 0;
}
