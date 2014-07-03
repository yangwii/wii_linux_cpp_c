#include <stdio.h>
#include <string.h>
#include <string.h>

void calcAllPermutation(char *perm, int from, int to);
void swap(char *perm, int i, int j);

int main(int argc, char **argv)
{
	char s[] = "abc";
	calcAllPermutation(s, 0, strlen(s) - 1);
	return 0;
}

void calcAllPermutation(char *perm, int from, int to)
{
	if(to <= 1)
	{
		return;
	}

	if(from == to)
	{
		for(int i = 0; i <= to; i++)
		{
			printf("%c", perm[i]);
		}
		printf("\n");
	}
	else
	{
		for(int j = from; j <= to; j++)
		{
			swap(perm, j, from);
			calcAllPermutation(perm, from + 1, to);
			swap(perm, j, from);//将字符串恢复原状，连续两次交换等于没有交换。
		}
	}
}

void swap(char *perm, int i, int j)
{
	char tmp = perm[i];
	perm[i] = perm[j];
	perm[j] = tmp;
}
