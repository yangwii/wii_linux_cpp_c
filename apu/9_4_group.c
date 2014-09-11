#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;
	printf("%d---%d\n", getpid(), getppid());
	if((pid = fork()) < 0)
	{
		printf("fork error\n");
		exit(-1);
	}
	else if(pid == 0)
	{
		printf("%d---%d\n", getpid(), getppid());
		exit(0);
	}

	if(setpgid(getpid(), getpid()) != 0)
	{
		printf("setpgid error\n");
	}
	printf("groupid---%d\n", getpgrp());//getprgp() == getpgid(0)

	if(waitpid(pid, NULL, 0) != pid)
	{
		printf("wait error\n");
		exit(-2);
	}
	exit(0);
}
