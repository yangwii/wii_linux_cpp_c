#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strprime(char *s);
int main(int argc, char *argv[])
{
	char s[] = "ABC";
	char r[] = "DBA";
	if(strprime(s) == strprime(r))
	{
		printf("是变位词\n");
	}
	return 0;
}

int strprime(char *s)
{
	const int p[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59,61, 67, 
			71, 73, 79, 83, 89, 97, 101};
	int f = 1;
	for(int i = 0; i < strlen(s); i++)
	{
		int x = p[s[i] - 'A'];
		if(f % x)
		{
			f *= x;
		}
	}

	return f;
}
