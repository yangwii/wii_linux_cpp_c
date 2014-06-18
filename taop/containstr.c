#include <stdio.h>
#include <stdlib.h>

bool stringContain(char *s, char *r);
bool stringContain_1(char *s, char *r);
bool stringContain_2(char *s, char *r);

int cmp(const void *a, const void *b)
{
	return *(char *)a - *(char *)b;
}

int main(int argc, char *argv[])
{
	return 0;
}

bool stringContain(char *s, char *r)
{
	for(int i = 0; i < strlen(r); i++)
	{
		int j;
		for(j = 0; j < strlen(s) && s[j] != r[i]; j++)
				;
		if(j >= strlen(s))
		{
			return false;
		}
	}
	return true;
}

bool stringContain_1(char *s, char *r)
{
	qsort(s, strlen(s), sizeof(s[0]), cmp);
	qsort(r, strlen(r), sizeof(r[0]), cmp);

	for(int pa = 0, pb = 0; pb < strlen(r);)
	{
		while((pa < strlen(s)) && (s[pa] < r[pb]))
		{
			pa++;
		}

		if(pa >= strlen(s) || (s[pa] > r[pb]))
		{
			return false;
		}

		++pb;
	}

	return true;
}

bool stringContain_2(char *s, char *r)
{
	int hash = 0;
	for(int i = 0; i < strlen(s); i++)
	{
		hash |= (1 << s[i] - 'A');
	}

	for(int i = 0; i < strlen(r); i++)
	{
		if((hash & (1 << (r[i] - 'A'))) == 0)
		{
			return false;
		}
	}

	return true;
}
