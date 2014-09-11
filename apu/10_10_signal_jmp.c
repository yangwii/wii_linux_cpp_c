#include <setjmp.h>
#include "apue.h"

#define MAXLINE 100
static void sig_alrm(int);
static jmp_buf env_alrm;

int main(void)
{
	int n;
	char line[MAXLINE];
	if(signal(SIGALRM, sig_alrm) == SIG_ERR)
	{
		printf("signal error\n");
	}
	if(setjmp(env_alrm) != 0)
	{
		printf("setjmp\n");
		exit(0);
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
	longjmp(env_alrm, 1);
}
