#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int s[], int l, int r);
int adjustArray(int s[], int l, int r);

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

	quicksort(s, 0, 9);
	
	printf("after SORT:  ");
	for(int i = 0; i < 10; i++)
	{
		printf("%d\t", s[i]);
	}
	printf("\n");
	return 0;
}

void quicksort(int s[], int l, int r)
{
	if(l < r)
	{
		int mid = adjustArray(s, l, r);
		quicksort(s, l, mid - 1);
		quicksort(s, mid + 1, r);
	}
}

int adjustArray(int s[], int l, int r)
{
	int i = l;
	int j = r;
	int x = s[l];

	while(i < j)
	{
		while(i < j && s[j] >= x)
		{
			j--;
		}
		if(i < j)
		{
			s[i++] = s[j];
		}

		while(i < j && s[i] < x)
		{
			i++;
		}
		if(i < j)
		{
			s[j--] = s[i];
		}
	}

	s[i] = x;
	return i;
}
