#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void leftShiftOne(char *s, int n);
void leftRotateString(char *s, int n, int m);

int main(int argc, char *argv[])
{
	char s[] = "hello";
	printf("%s\n", s);
	leftRotateString(s, strlen(s), 3);
	printf("%s\n", s);
	return 0;
}

void leftShiftOne(char *s, int n)
{
	char t = s[0];
	for(int i = 1; i < n; i++)
	{
		s[i - 1] = s[i];
	}
	s[n - 1] = t;
}

void leftRotateString(char *s, int n, int m)
{
	while(m--)
	{
		leftShiftOne(s, n);
	}
}
