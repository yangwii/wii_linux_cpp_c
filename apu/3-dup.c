#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

void main(void)
{
	int d1 = dup(STDIN_FILENO);
	printf("fd is %d\n", d1);

	int newfd = 123;
	int d2 = dup2(STDIN_FILENO, newfd);
	printf("fd is %d\n", newfd);

	int newfd_2 = 456;
	int d3 = dup3(STDIN_FILENO, newfd_2, O_CLOEXEC);
	printf("fd is %d\n", d3);
}
