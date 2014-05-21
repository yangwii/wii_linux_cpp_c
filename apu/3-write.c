#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

#define CONTENT "hello world"
#define LEN  sizeof(CONTENT)

int main(void)
{
	char filename[] = "test-3-write.txt";
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	int fd = creat(filename, mode);
	if(fd == -1)
	{
		printf("create file failed\n");
		return 1;
	}

	int write_byte = write(fd, CONTENT, LEN);

	if(write_byte != LEN)
	{
		printf("write file fail\n");
		return 2;
	}
	return 0;
}
