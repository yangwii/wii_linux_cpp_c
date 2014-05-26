#include <pthread.h>
#include <stdio.h>
#include <math.h>

#define ITERATIONS 10000

pthread_mutex_t mutex;
double target;

void* opponent(void *arg)
{
	for(int i = 0; i < ITERATIONS; i++)
	{
		pthread_mutex_lock(&mutex);
		target -= target * 2 + tan(target);
		pthread_mutex_unlock(&mutex);
	}

	return NULL;
}

int main(void)
{
	pthread_t other;
	target = 5.0;

	if(pthread_mutex_init(&mutex, NULL))
	{
		printf("init mutext error\n");
		return 1;
	}

	if(pthread_create(&other, NULL, opponent, NULL))
	{
		printf("create thread error\n");
		return 2;
	}

	for(int i = 0; i < ITERATIONS; i++)
	{
		pthread_mutex_lock(&mutex);
		target -= target * 2 + tan(target);
		pthread_mutex_unlock(&mutex);
	}

	if(pthread_join(other, NULL))
	{
		printf("join thread error\n");
		return 3;
	}

	pthread_mutex_destroy(&mutex);

	printf("Result:%f\n", target);

	return 0;
}

