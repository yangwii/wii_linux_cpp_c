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
		if((pid = fork()) < 0)
		{
			printf("fork error\n");
			exit(-2);
		}
		else if(pid > 0)
		{
			exit(0);
		}
		sleep(5);
		printf("second child, ppid = %d\n", getppid());
		exit(0);
	}

	if(waitpid(pid, NULL, 0) != pid)
	{
		printf("waitpid error\n");
		exit(-3);
	}
	exit(0);
}
