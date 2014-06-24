#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void moveneg1(int s[], int n);

int main(int argc, char *argv[])
{
	srand(time(NULL));
	int s[10];
	int q[10];
	for(int i = 0; i < 10; i++)
	{
		s[i] = q[i] = rand() % 10 - 5;
	}

	printf("after move:\t");
	for(int i = 0; i < 10; i++)
	{
		printf("%d\t", s[i]);
	}
	printf("\n");

	moveneg1(s, 10);

	printf("after move:\t");
	for(int i = 0; i < 10; i++)
	{
		printf("%d\t", s[i]);
	}
	printf("\n");
	return 0;
}

void moveneg1(int s[], int n)
{
	for(int i = 0, k = 0; i < n; i++)
	{
		if(s[k] > 0)
		{
			int tmp = s[k];
			int j = 0;
			for(j = k; j < n - 1; j++)
			{
				s[j] = s[j + 1];
			}
			s[j] = tmp;
		}
		else
		{
			k++;
		}
	}
}
