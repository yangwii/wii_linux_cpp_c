#include "apue.h"

static void sig_usr(int);

int main(void)
{
	if(signal(SIGUSR1, sig_usr) == SIG_ERR)
	{
		printf("can not catch sigusr1\n");
	}
	else if(signal(SIGUSR2, sig_usr) == SIG_ERR)
	{
		printf("can not catch sigusr2\n");
	}
	for(; ;)
		pause();
}

static void sig_usr(int signo)
{
	if(signo == SIGUSR1)
	{
		printf("received sigusr1\n");
	}
	else if(signo == SIGUSR2)
	{
		printf("received sigusr2\n");
	}
	else
	{
		printf("error\n");
	}
}
