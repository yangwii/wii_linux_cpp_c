#include <unistd.h>
#include <stdio.h>

int main(void)
{
	printf("Process id = %d\n", getpid());
	return 0;
}
