#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseString(char *s, int from, int end);
void leftRotateString(char *s, int n, int m);

int main(int argc, char **argv)
{
	char s[] = "hello";
	printf("%s\n", s);
	leftRotateString(s, strlen(s), 3);
	printf("%s\n", s);
	return 0;
}

void reverseString(char *s, int from, int end)
{
	while(from < end)
	{
		char t = s[from];
		s[from++] = s[end];
		s[end--] = t;
	}
}

void leftRotateString(char *s, int n, int m)
{
	reverseString(s, 0, m - 1);
	reverseString(s, m, n - 1);
	reverseString(s, 0, n - 1);
}
