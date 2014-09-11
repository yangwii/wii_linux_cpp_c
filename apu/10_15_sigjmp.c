#include "apue.h"
#include <time.h>
#include <setjmp.h>

static void sig_usr1(int), sig_alrm(int);
static sigjmp_buf jmpbuf;
static volatile sig_atomic_t canjump;
int main(void)
{
	if(signal(SIGUSR1, sig_usr1) == SIG_ERR)
	{
		printf("sigusr1 error\n");
	}
	if(signal(SIGALRM, sig_alrm) == SIG_ERR)
	{
		printf("sigalrm error\n");
	}

	printf("starting...\n");

	if(sigsetjmp(jmpbuf, 1))
	{
		printf("ending...\n");
		exit(0);
	}

	canjump = 1;

	for(; ;)
		pause();
}

static void sig_usr1(int signo)
{
	time_t starttime;
	if(canjump == 0)
	{
		return;
	}

	printf("start sig_usr1:\n");
	alarm(3);
	for(; ;)
		if(time(NULL) > starttime + 5)
			break;
	printf("finish sig_usr1\n");

	canjump = 0;
	siglongjump(jmpbuf, 1);
}

static void sig_alrm(int signo)
{
	printf("in sig_alrm\n");
}
