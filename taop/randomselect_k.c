#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int s[], int l, int r);
int random_partition(int s[], int l, int r);
int random_select(int s[], int l, int r, int k);
void swap(int *a, int *b);
int random_i(int l, int r);

int cmp(const void* a, const void* b)
{
	return *((int *)a) - *((int *)b);
}

int main(int argc, char **argv)
{
	srand(time(NULL));
	int s[10];
	for(int i = 0; i < 10; i++)
	{
		s[i] = rand() % 100;
	}
	
	printf("Data:\t");
	for(int i = 0; i < 10; i++)
	{
		printf("%d\t", s[i]);
	}
	printf("\n");
	
	printf("%d\n", random_select(s, 0, 9, 4));
	
	qsort(s, 10, sizeof(s[0]), cmp);
	for(int i = 0; i < 10; i++)
	{
		printf("%d\t", s[i]);
	}
	printf("\n");
	return 0;
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int random_i(int l, int r)
{
	int k;
	while(true)
	{
		k = rand() % 10;
		//printf("%d\n", k);
		if(k >= l && k <= r)
			break;
	}
	return k;
}

int partition(int s[], int l, int r)
{
	int x = s[r];
	int i = l - 1;
	for(int j = l; j <= r - 1; j++)
	{
		if(s[j] <= x)
		{
			i++;
			swap(&s[i], &s[j]);
		}
	}
	swap(&s[i + 1], &s[r]);

	return i + 1;
}

int random_partition(int s[], int l, int r)
{
	int i = random_i(l, r);
	swap(&s[i], &s[r]);
	return partition(s, l, r);
}

int random_select(int s[], int l, int r, int k)
{
	if(l == r)
	{
		return s[l];
	}
	int q = random_partition(s, l, r);
	int i = q - l + 1;

	if(i == k)
	{
		return s[q];
	}
	else if(i > k)
	{
		return random_select(s, l, q - 1, k);
	}
	else
	{
		return random_select(s, q + 1, r, k - i);
	}
}
