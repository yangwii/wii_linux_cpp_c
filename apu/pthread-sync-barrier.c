#define _XOPEN_SOURCE 600
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#define ROWS 100
#define COLS 100
#define THREADS 10

double initial_matrix[ROWS][COLS];
double final_matrix[ROWS][COLS];

pthread_barrier_t barr;
extern void DotProduct(int row, int col, double source[ROWS][COLS], double destination[ROWS][COLS]);
extern double determinant(double matrix[ROWS][COLS]);

void* entry_point(void *arg)
{
	int rank = (int)arg;

	for(int i = rank * ROWS / THREADS; i < (rank + 1) * THREADS; i++)
	{
		for(int j = 0; j < COLS; j++)
		{
			DotProduct(i, j, initial_matrix, final_matrix);
		}
	}

	int rc = pthread_barrier_wait(&barr);
	if(rc != 0 && rc != PTHREAD_BARRIER_SERIAL_THREAD)
	{
		printf("Could not wait on barrier\n");
		exit(-1);
	}

	for(int i = rank * ROWS / THREADS; i < (rank + 1) * THREADS; i++)
	{
		for(int j = 0; j < COLS; j++)
		{
			DotProduct(i, j, initial_matrix, final_matrix);
		}
	}
}

int main()
{
	printf("dd");
	return 0;
}
