#include <sys/stat.h>
#include <stdio.h>

#define READ_PERMISSION 4
#define WRITE_PERMISSION 2
#define EXECUTE_PERMISSION 1

#define RWX_PERMISSION 7

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("usage:./a.out filepath\n");
		return 1;
	}

	struct stat file;
	char *filename = argv[1];
	if(stat(filename, &file) == -1)
	{
		printf("get file info fail\n");
		return 2;
	}

	unsigned int owner = 0, group = 0, other = 0;
	if(file.st_mode & S_IRWXU == S_IRWXU)
	{
		owner = RWX_PERMISSION;
	}
	else
	{
		if(file.st_mode & S_IRUSR)
		{
			owner += READ_PERMISSION;
		}
		if(file.st_mode & S_IWUSR)
		{
			owner += WRITE_PERMISSION;
		}
		if(file.st_mode & S_IXUSR)
		{
			owner += EXECUTE_PERMISSION;
		}
	}

	if(file.st_mode & S_IRWXG == S_IRWXG)
	{
		group = RWX_PERMISSION;
	}
	else
	{
		if(file.st_mode & S_IRGRP)
		{
			group += READ_PERMISSION;
		}
		if(file.st_mode & S_IWGRP)
		{
			group  += WRITE_PERMISSION;
		}
		if(file.st_mode & S_IXGRP)
		{
			group += EXECUTE_PERMISSION;
		}
	}

	if(file.st_mode & S_IRWXO == S_IRWXO)
	{
		other = RWX_PERMISSION;
	}
	else
	{
		if(file.st_mode & S_IROTH)
		{
			other += READ_PERMISSION;
		}
		if(file.st_mode & S_IWOTH)
		{
			other += WRITE_PERMISSION;
		}
		if(file.st_mode & S_IWGRP)
		{
			other += EXECUTE_PERMISSION;
		}
	}

	printf("file %s permission=%u:%u:%u", filename, owner, group, other);
	return 0;
}
