#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shellsort_1(int s[], int n);
void shellsort_2(int s[], int n);
void shellsort_3(int s[], int n);//此算法来自Wikipeida

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

	shellsort_1(s, 10);

	printf("after SORT_1:  ");
	for(int i = 0; i < 10; i++)
	{
		printf("%d\t", s[i]);
	}
	printf("\n");

	shellsort_2(s, 10);

	printf("after SORT_2:  ");
	for(int i = 0; i < 10; i++)
	{
		printf("%d\t", s[i]);
	}
	printf("\n");

	shellsort_3(s, 10);

	printf("after SORT_3:  ");
	for(int i = 0; i < 10; i++)
	{
		printf("%d\t", s[i]);
	}
	printf("\n");
	return 0;
}

void shellsort_1(int s[], int n)
{
	int i, j, gap;
	for(gap = n / 2; gap > 0; gap = gap / 2)
	{
		for(i = 0; i < gap; i++)
		{
			for(j = i + gap; j < n; j += gap)
			{
				if(s[j] < s[j - gap])
				{
					int tmp = s[j];
					int k = j - gap;
					while(s[k] > tmp && k >= 0)
					{
						s[k + gap] = s[k];
						k -= gap;
					}
					s[k + gap] = tmp;
				}
			}
		}
	}
}

void shellsort_2(int s[], int n)
{
	int i, j, gap, tmp;
	for(gap = n / 2; gap > 0; gap /= 2)
	{
		for(i = gap; i < n; i++)
		{
			tmp = s[i];
			for(j = i - gap; s[j] > tmp && j >= 0; j -= gap)
			{
				s[j + gap] = s[j];
			}
			s[j + gap] = tmp;
		}
	}
}

void shellsort_3(int s[], int n)
{
	int i, j, gap, tmp;
	while(gap <= n)
	{
		gap = gap * 3 + 1;
	}

	while(gap > 0)
	{
		for(i = gap; i < n; i++)
		{
			j = i - gap;
			tmp = s[i];
			while(j >= 0 && s[j] > tmp)
			{
				s[j + gap] = s[j];
				j = j - gap;
			}
			s[j + gap] = tmp;
		}
		gap = (gap - 1) / 3;
	}
}
