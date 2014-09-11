#include "apue.h"
#include <pthread.h>

int quitflag;
sigset_t mask;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t _wait = PTHREAD_COND_INITIALIZER;

void * thr_fn(void *arg)
{
	int err, signo;
	for(; ;)
	{
		err = sigwait(&mask, &signo);
		if(err != 0)
		{
			pthread_exit((void*)0);
		}
		switch(signo)
		{
			case SIGINT:
				printf("\ninterrupt\n");
				break;
			case SIGQUIT:
				pthread_mutex_lock(&lock);
				quitflag = 1;
				pthread_mutex_unlock(&lock);
				pthread_cond_signal(&_wait);
				return 0;
			default:
				printf("unexpected signal%d\n", signo);
				exit(1);
		}
	}
}

int main(void)
{
	int err;
	sigset_t oldmask;
	pthread_t tid;

	sigemptyset(&mask);
	sigaddset(&mask, SIGINT);
	sigaddset(&mask, SIGQUIT);

	if((err = pthread_sigmask(SIG_BLOCK, &mask, &oldmask)) != 0)
	{
		
		printf("sigmask error\n");
		exit(-1);
	}

	err = pthread_create(&tid, NULL, thr_fn, NULL);
	if(err != 0)
	{
		printf("pthread create error\n");
		exit(-2);
	}

	pthread_mutex_lock(&lock);

	sleep(5);
	pthread_kill(tid, SIGINT);
	sleep(5);
	kill(getpid(), SIGQUIT);
	while(quitflag == 0)
		pthread_cond_wait(&_wait, &lock);
	pthread_mutex_unlock(&lock);

	quitflag = 0;
	if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		printf("sigpromask error\n");

	exit(0);
}
