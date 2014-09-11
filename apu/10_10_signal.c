#include "apue.h"

#define MAXLINE 100
static void sig_alrm(int);

int main(void)
{
	int n;
	char line[100];
	if(signal(SIGALRM, sig_alrm) == SIG_ERR)
	{
		printf("signal error\n");
	}
	alarm(10);
	if((n = read(STDIN_FILENO, line, MAXLINE)) < 0)
	{
		printf("read error\n");
	}
	alarm(0);
	write(STDOUT_FILENO, line, n);
	exit(0);
}

static void sig_alrm(int signo)
{
	printf("sig_alrm\n");
}
