#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid = fork();
	
	if(pid == 0)
	{
		printf("child running\n");
	}
	else if(pid > 0)
	{
		wait(NULL);
		printf("parent running\n");
	}
	return 0;
}
