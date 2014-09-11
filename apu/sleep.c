#include "apue.h"

static void sig_alrm(int signo)
{

}

unsigned int sleep(unsigned int nsecs)
{
	struct sigaction newact, oldact;
	sigset_t newmask, oldmask, suspmask;
	unsigned int unsleep;

	newact.sa_handler = sig_alrm;
	sigemptyset(&newact.sa_mask);
	newact.sa_flag = 0;
	sigaction(SIGALRM, &newact, &oldact);


	sigemptyset(&newmask);
	sigaddset(&newmask, SIGALRM);
	sigprocmask(SIG_BLOCK, &newmask, &oldmask);

	alarm(nsecs);

	suspmask = oldmask;
	sigdelset(&suspmask, SIGALRM);
	sigsuspend(&suspmask);

	unsleep = sleep(0);

	sigaction(SIGALRM, &oldact, NULL);

	sigprocmask(SIG_SETMASK, &oldmask, NULL);

	return unsleep;
}
