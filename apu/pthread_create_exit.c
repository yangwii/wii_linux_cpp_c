#include <pthread.h>
#include <stdio.h>

#define N 5

void *PrintHello(void *threadid)
{
	long tid;
	tid = (long)threadid;
	printf("Hello world!tid:%ld\n", tid);
	pthread_exit(NULL);
}

int main(int argc, char **argv)
{
	pthread_t threads[N];
	int rc;
	long t;

	for(t = 0; t < N; t++)
	{
		printf("In main:Create thread %ld\n", t);
		rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);

		if(rc)
		{
			printf("Error: Create thread fail\n");
			exit(-1);
		}
	}

	pthread_exit(NULL);
}
