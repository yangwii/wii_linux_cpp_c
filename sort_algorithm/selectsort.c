#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectsort(int s[], int n);

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

	selectsort(s, 10);

	printf("after SORT:  ");
	for(int i = 0; i < 10; i++)
	{
		printf("%d\t", s[i]);
	}
	printf("\n");
	return 0;
}

void selectsort(int s[], int n)
{
	int i, j, minindex , tmp;
	for(i = 0; i < n; i++)
	{
		minindex = i;
		for(j = i + 1; j < n; j++)
		{
			if(s[j] < s[minindex])
			{
				minindex = j;
			}
		}
		if(minindex != i)
		{
			tmp = s[minindex];
			s[minindex] = s[i];
			s[i] = tmp;
		}
	}
}
