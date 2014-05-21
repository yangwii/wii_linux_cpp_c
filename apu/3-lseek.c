#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>

#define CONTENT "hello world"
#define LEN  sizeof(CONTENT)

int main(void)
{
	char filename[] = "test-3-lseek.txt";
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	int fd = open(filename, O_RDWR | O_CREAT, mode);
	if(fd == -1)
	{
		printf("create file fail\n");
		return 1;
	}

	if(write(fd, CONTENT, LEN) != LEN)
	{
		printf("write file fail\n");
		return 2;
	}

	if(lseek(fd, 0, SEEK_SET) == -1)
	{
		printf("seek file fail\n");
		return 3;
	}

	char buf[LEN];

	if(read(fd, buf, LEN) != LEN)
	{
		printf("read file fail\n");
		return 4;
	}

	printf("text-->%s\n", buf);

	return 0;
}
