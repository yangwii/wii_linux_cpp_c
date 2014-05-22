#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>

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
		printf("open file failed\n");
		return 2;
	}

	off_t data_offset;
	data_offset = lseek(fd, 0, SEEK_DATA);
	if(data_offset == -1)
	{
		printf("get data offset fail\n");
		return 3;
	}

	printf("first data offset of file %s %lld\n", filename, (long long)data_offset);

	off_t hole_offset;
	hole_offset = lseek(fd, 0, SEEK_HOLE);
	if(hole_offset == -1)
	{
		printf("get hole offset fail\n");
		return 4;
	}

	printf("first data offset of file %s %lld\n", filename, (long long)hole_offset);
	return 0;
}
