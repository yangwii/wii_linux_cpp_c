#include "apue.h"

int main(void)
{
	pid_t pid;
	if((pid = fork()) < 0)
	{
		printf("fork error\n");
		exit(-1);
	}
	else if(pid == 0)
	{
		sleep(10);
		printf("pid---%d\n", getpid());
		printf("sid---%d\n", setsid());
		exit(0);
	}
	else
	{
		exit(0);
	}
}
