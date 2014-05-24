#include <unistd.h>
#include <stdio.h>

int main(void)
{
	pid_t child_id;
	child_id = fork();

	if(child_id == 0)
	{
		printf("child process running, id = %d\n", getpid());
		printf("child proces`s parent id = %d\n", getppid());
	}
	else if(child_id > 0)
	{
		printf("parent process running, id = %d\n", getpid());
	}
	else
	{
		printf("fork error\n");
	}
	return 0;
}
