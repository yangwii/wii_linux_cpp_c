#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubblesort(int s[], int n);
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
	bubblesort(s, 10);
	printf("after SORT:  ");
	for(int i = 0; i < 10; i++)
	{
		printf("%d\t", s[i]);
	}
	printf("\n");
	return 0;
}

void bubblesort(int s[], int n)
{
	int j, k, tmp;
	bool flag;
	flag = true;
	k = n;
	while(flag)
	{
		flag = false;
		for(j = 0; j < k - 1; j++)
		{
			if(s[j] < s[j + 1])
			{
				tmp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = tmp;
				flag = true;
			}
		}
		k--;
	}
}
