#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid = fork();
	if(pid == -1)
	{
		printf("fork error\n");
		return 1;
	}
	
	int status;
	if(pid != 0)
	{
		wait(&status);
		if(WIFEXITED(status))
		{
			printf("child id %d, normal termianl, status--%d\n", pid,  WEXITSTATUS(status));
		}
	}
	else
	{
		return execl("hole", (char *)NULL);
	}

	return 0;
}
