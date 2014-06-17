#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reversestr(char *s, int l, int r);
void wordreverse(char *s);

int main(int argc, char **argv)
{
	char s[] = "I am a student";
	printf("%s\n", s);
	//leftRotateString(s, strlen(s), 3);
	wordreverse(s);
	printf("%s\n", s);
	return 0;
}

void reversestr(char *s, int l, int r)
{
	while(l < r)
	{
		char t = s[l];
		s[l++]  = s[r];
		s[r--] = t;
	}
}

void wordreverse(char *s)
{
	char *p = s;
	int j = 0;
	int len = strlen(s);
	reversestr(s, 0, len - 1);
	printf("%s\n", s);
	s[len] = ' ';
	s[len + 1] = '\0';
	for(int i = 0, j = i; i < strlen(s); i++)
	{
		if(s[i] == ' ')
		{
			reversestr(s, j, i - 1);
			j = i+1;
		}
	}
	s[len] = '\0';
}
