#include <pthread.h>
#include "apue.h"

pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;

void prepare(void)
{
	printf("prepareing locks,,,\n");
	pthread_mutex_lock(&lock1);
	pthread_mutex_lock(&lock2);
}

void parent(void)
{
	printf("parent unlocking locks,,,\n");
	pthread_mutex_unlock(&lock1);
	pthread_mutex_unlock(&lock2);
}

void child(void)
{
	printf("child unlocking locks,,,\n");
	pthread_mutex_unlock(&lock1);
	pthread_mutex_unlock(&lock2);
}

void *thr_fn(void *arg)
{
	printf("thread started,,,\n");
	pause();
	return 0;
}

int main(void)
{
	int err;
	pid_t pid;
	pthread_t tid;

	if((err = pthread_atfork(prepare, parent, child)) != 0)
	{
		printf("pthread atfork error\n");
		exit(0);
	}

	err = pthread_create(&tid, NULL, thr_fn, NULL);
	if(err != 0)
	{
		printf("pthread create error\n");
		exit(0);
	}

	sleep(2);
	printf("parent about to fork...\n");
	if((pid = fork()) < 0)
	{
		printf("fork error\n");
		exit(0);
	}
	else if(pid == 0)
	{
		printf("child returned from fork..\n");
	}
	else
	{
		printf("parent returned from fork..\n");
	}

	exit(0);
}
