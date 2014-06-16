#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergesort(int s[], int n, int first, int last);
void mergeArray(int s[], int n, int first, int mid, int last);

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

	mergesort(s, 10, 0, 9);
	
	printf("after SORT:  ");
	for(int i = 0; i < 10; i++)
	{
		printf("%d\t", s[i]);
	}
	printf("\n");

	return 0;
}

void mergesort(int s[], int n, int first, int last)
{
	if(first < last)
	{
		int mid = (first + last) / 2;
		mergesort(s, n, first, mid);
		mergesort(s, n, mid + 1, last);
		mergeArray(s, n, first, mid, last);
	}
}

void mergeArray(int s[], int length, int first, int mid, int last)
{
	int i = first, j = mid + 1;
	int m = mid, n = last;
	int k = 0;
	int a[length];

	while(i <= m && j <= n)
	{
		if(s[i] < s[j])
		{
			a[k++] = s[i++];
		}
		else
		{
			a[k++] = s[j++];
		}
	}

	while(i <= m)
	{
		a[k++] = s[i++];
	}

	while(j <= n)
	{
		a[k++] = s[j++];
	}

	for(int ii = first; ii <= last; ii++)
	{
		s[ii] = a[ii - first];
	}
}
