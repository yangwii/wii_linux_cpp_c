#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>

#define BUF_SIZE 1024
#define READ_SIZE 10

off_t get_current_offset(int fd);
int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("usange:./out filename\n");
		return 1;
	}
	char *filename = argv[1];
	int fd = open(filename, O_RDONLY);

	if(fd == -1)
	{
		printf("open file fail\n");
		return 2;
	}

	off_t before_read_offset = get_current_offset(fd);
	char buf[BUF_SIZE];

	if(read(fd, buf, READ_SIZE) == -1)
	{
		printf("read file fail\n");
		return 3;
	}

	off_t after_read_offset = get_current_offset(fd);
	printf("before %lld, after %lld\n", (long long)before_read_offset, (long long)after_read_offset);

	off_t before_pread_offset = get_current_offset(fd);

	if(pread(fd, buf, READ_SIZE, before_pread_offset) == -1)
	{
		printf("pread file fail\n");
		return 4;
	}

	off_t after_pread_offset = get_current_offset(fd);
	printf("before %lld, after %lld\n", (long long)before_pread_offset, (long long)after_pread_offset);

	return 0;
}

off_t get_current_offset(int fd)
{
	return lseek(fd, 0, SEEK_CUR);
}
