#include <unistd.h>
#include <stdio.h>

int main(void)
{
	printf("parent pi = %d\n", getppid());
	printf("uid = %d\n", getuid());
	printf("Euid = %d\n", geteuid());
	printf("gid = %d\n", getgid());
	printf("egid = %d\n", getegid());

	return 0;
}
