#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int left(int i);
int right(int i);
void max_heapify(int s[], int n, int i);
void build_max_heap(int s[], int n);
void heapsort(int s[], int n);

int main(int argv, char **argc)
{
	srand(time(NULL));
	int s[10];
	for(int i = 0; i < 10; i++)
	{
		s[i] = rand() % 100;
	}
	
	printf("before SORT:  ");
	for(int i = 0; i < 10; i++)
	{
		printf("%d\t", s[i]);
	}
	printf("\n");

	heapsort(s, 10);

	printf("after SORT:  ");
	for(int i = 0; i < 10; i++)
	{
		printf("%d\t", s[i]);
	}
	printf("\n");
	
	return 0;
}

int left(int i)
{
	return 2 * i + 1;
}

int right(int i)
{
	return 2 * i + 2;
}

void max_heapify(int s[], int n, int i)
{
	int l = left(i);
	int r = right(i);
	int large = 0;
	
	if(l < n && s[l] > s[i])
	{
		large = l;
	}
	else
	{
		large = i;
	}

	if(r < n && s[r] > s[large])
	{
		large = r;
	}

	if(large != i)
	{
		int tmp = s[large];
		s[large] = s[i];
		s[i] = tmp;

		max_heapify(s, n, large);
	}
}

void build_max_heap(int s[], int n)
{
	for(int i = n / 2; i >= 0; i--)
	{
		max_heapify(s, n, i);
	}
}

void heapsort(int s[], int n)
{
	build_max_heap(s, n);
	for(int i  = n - 1; i >= 1; i--)
	{
		int tmp = s[i];
		s[i] = s[0];
		s[0] = tmp;
		max_heapify(s, --n, 0);
	}
}
