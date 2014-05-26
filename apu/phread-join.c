#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 4

void *BusyWork(void *t)
{
	int i;
	long tid;
	double result = 0; 
	tid = (long)t;
	printf("Thread %ld starting...\n", tid);

	for(i = 0; i < 1000000; i++)
	{
		result = result + sin(i) * tan(i);
	}

	printf("Thread %ld done. Result = %e\n", tid, result);

	pthread_exit(NULL);
}

int main(void)
{
	pthread_t thread[N];
	pthread_attr_t attr;

	int rc;
	long t;
	void *status;

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	for(t = 0; t < N; t++)
	{
		printf("Main:create thread %ld\n", t);
		
		rc = pthread_create(&thread[t], NULL, BusyWork, (void *)t);
	
		if(rc)
		{
			printf("Error: create thread failed\n");
			exit(-1);
		}
	}

	pthread_attr_destroy(&attr);
	for(t = 0; t < N; t++)
	{
		rc = pthread_join(thread[t], &status);

		if(rc)
		{
			printf("join error\n");
			exit(-1);
		}
		printf("Main: completeed join with thread %ld having a status of %ld\n", t, (long)status);
	}
	printf("Main: program completed. Exiting.\n");

	pthread_exit(NULL);
}
