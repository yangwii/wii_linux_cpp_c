#include <unistd.h>
#include <stdio.h>
#include <wait.h>

int main(void)
{
	int status;
	pid_t pid = fork();

	if(pid == -1)
	{
		printf("fork error\n");
		return 1;
	}

	if(pid != 0)
	{
		wait(&status);

		if(WIFEXITED(status))
		{
			printf("normal terminated, status--%d\n", WEXITSTATUS(status));
		}
		else
		{
			printf("not normal\n");
		}
	}
	else
	{
		//return 2;
	}
	return 0;
}
