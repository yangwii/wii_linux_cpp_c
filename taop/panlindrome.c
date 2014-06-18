#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isPalindrome_1(const char *s);
bool isPalindrome_2(const char *s);

int main(int argc, char *argv[])
{
	return 0;
}

bool isPalindrome_1(const char *s)
{
	if(s == NULL)
	{
		return false;
	}

	int len = strlen(s);
	char *front, *back;
	front = s;
	back = s + len - 1;
	
	while(front < back)
	{
		if(*front != *back)
		{
			return false;
		}

		++front;
		++back;
	}

	return false;
}

bool isPalindrome_2(const char *s)
{
	if(s == NULL)
	{
		return false;
	}

	int len = strlen(s);
	char *first, *second;

	int m = ((len >> 1) - 1) >= 0 ? (len >> 1) - 1 : 0;
	first = s + m;
	second = s + len - 1 - m;

	while(first >= s)
	{
		if(s[first--] != s[second++])
		{
			return false;
		}
	}

	return true;
}
