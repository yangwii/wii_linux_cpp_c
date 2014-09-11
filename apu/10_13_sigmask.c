#include "apue.h"

static void sig_quit(int);

int main(void)
{
	sigset_t newmask, oldmask, pendmask;
	if(signal(SIGQUIT, sig_quit) == SIG_ERR)
	{
		printf("signal error\n");
	}


	sigemptyset(&newmask);
	sigaddset(&newmask, SIGQUIT);
	if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
	{
		printf("1  sigprocmask error\n");
	}
	sleep(5);

	if(sigpending(&pendmask) < 0)
	{
		printf("sigpending error\n");
	}
	if(sigismember(&pendmask, SIGQUIT))
	{
		printf("SIGQUIT pending\n");
	}

	if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
	{
		printf("2  sigprocmask error\n");
	}
	sleep(5);

	exit(0);
}

static void sig_quit(int signo)
{
	printf("catch sigquit\n");
	if(signal(SIGQUIT, SIG_DFL) == SIG_ERR)
	{
		printf("can not reset sigquit\n");
	}
}
