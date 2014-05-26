#include <pthread.h>
#include <stdio.h>

pthread_t ntid;

void printids(const char *s)
{
	pid_t pid = getpid();
	pthread_t tid = pthread_self();

	printf("%s pid %u tid %u\n", s, (unsigned int)pid, (unsigned int)tid);
}

void* thr_fn(void *arg)
{
	printids("new thread:");
	return ((void *)0);
}

int main()
{
	int err = pthread_create(&ntid, NULL, thr_fn, NULL);
	if(err != 0)
	{
		printf("can not create thread\n");
		return 1;
	}

	printids("main thread:");
	sleep(1);

	return 0;
}
