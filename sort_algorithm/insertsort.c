#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertsort(int s[], int n);
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

	insertsort(s, 10);
	printf("after SORT:  ");
	for(int i = 0; i < 10; i++)
	{
		printf("%d\t", s[i]);
	}
	printf("\n");
	return 0;
}

void insertsort(int s[], int n)
{
	int tmp;
	int i = 0;
	for(int j = 1; j < n; j++)
	{
		tmp = s[j];
		for(i = j - 1; i >= 0 && s[i] > tmp; i--)
		{
			s[i + 1] = s[i];
		}
		s[i + 1] = tmp;
	}
}
