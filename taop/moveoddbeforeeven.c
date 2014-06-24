#include <stdio.h>
#include <time.h>
#include <stdlib.h>

bool isOdd(int data);//判断是否为奇数
void swap(int *a, int *b);//交换两个元素
void moveodd_even(int s[], int n);
void moveodd_even1(int s[], int n);
void moveodd_even2(int s[], int n);

int main(int argc, char *argv[])
{
	srand(time(NULL));
	int s[10];
	int q[10];
	for(int i = 0; i < 10; i++)
	{
		s[i] = q[i] = rand() % 10 + 1;
	}

	printf("before move:\t");
	for(int i = 0; i < 10; i++)
	{
		printf("%d\t", s[i]);
	}
	printf("\n");

	moveodd_even(s, 10);
	moveodd_even1(q, 10);

	printf("after move:\t");
	for(int i = 0; i < 10; i++)
	{
		printf("%d\t", s[i]);
	}
	printf("\n");
	return 0;
}

bool isOdd(int data)//判断是否为奇数
{
	return data % 2 != 0;
}

void swap(int *a, int *b)//交换两个元素
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void moveodd_even(int s[], int n)
{
	if(s == NULL || n == 0)
	{
		return;
	}

	int counter = 0;
	int l = 0;
	int r = n - 1;
	while(l < r)
	{
		counter++;
		if(isOdd(s[l]))
		{
			l++;
		}
		else if(!isOdd(s[r]))
		{
			r--;
		}
		else
		{
			swap(&s[l], &s[r]);
			l++;
			r--;
		}
	}
	printf("%d\n", counter);			
}

void moveodd_even1(int s[], int n)
{
	if(s == NULL || n == 0)
	{
		return;
	}

	int counter = 0;
	int l = 0;
	int r = n - 1;
	while(l < r)
	{
		counter++;
		if(isOdd(s[l]))
		{
			l++;
		}
		else if(!isOdd(s[r]))
		{
			r--;
		}
		else
		{
			swap(&s[l], &s[r]);
		}
	}
	printf("%d\n", counter);			
}

void moveodd_even2(int s[], int n)
{
	if(s == NULL || n == 0)
	{
		return;
	}
	int l = 0;
	int r = n - 1;
	int x = s[r];

	int i = l - 1;
	for(int j = l; j <= r - 1; j++)
	{
		if(isOdd(s[j]))
		{
			i = i + 1;
			swap(&s[i], &s[j]);
		}
	}

	swap(&s[i + 1], &s[r]);
}
