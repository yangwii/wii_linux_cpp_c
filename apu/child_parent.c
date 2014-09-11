#include "apue.h"

static volatile sig_atomic_t sigflag;
static sigset_t newmask, oldmask, zeromask;

static void sig_usr(int signo)
{
	sigflag = 1;
	printf("sig_usr\n");
}

void TELL_WAIT()
{
	if(signal(SIGUSR1, sig_usr) == SIG_ERR)
	{
		printf("signal sigusr1 error\n");
	}
	if(signal(SIGUSR2, sig_usr) == SIG_ERR)
	{
		printf("signal sigusr2 error\n");
	}

	sigemptyset(&zeromask);
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGUSR1);
	sigaddset(&newmask, SIGUSR2);
	sigprocmask(SIG_BLOCK, &newmask, &oldmask);

}

void TELL_PARENT(pid_t pid)
{
	kill(pid, SIGUSR2);
}

void WAIT_PARENT(void)
{
	while(sigflag == 0)
		sigsuspend(&zeromask);

	sigflag = 0;
	if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
	{
		printf("sigprocmask error\n");
	}
}

void TELL_CHILD(pid_t pid)
{
	kill(getpid(), SIGUSR1);
}

void WAIT_CHILD(void)
{
	while(sigflag == 0)
		sigsuspend(&zeromask);

	sigflag = 0;
	if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
	{
		printf("sigprocmask error\n");
	}
}
volatile int glob = 0;
int main(void)
{
	pid_t pid;
	TELL_WAIT();

	printf("%d\n", getpid());
	if((pid = fork()) < 0)
	{
		printf("fork error\n");
	}
	else if(pid == 0)
	{
		printf("child\n");
		WAIT_PARENT();
		glob++;
		printf("%d--->%d\n", getpid(), glob);
		//TELL_PARENT(getppid());
	}
	else
	{
		glob++;
		sleep(1);
		printf("%d--->%d\n", getpid(), glob);
		TELL_CHILD(pid);
		//WAIT_CHILD();
	}
	exit(0);
}
