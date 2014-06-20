#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longestPalindrome(char *s);

int main(int argc, char **argv)
{
	char s[] = "abba";
	printf("%d\n", longestPalindrome(s));
	return 0;
}

int longestPalindrome(char *s)
{
	int i, j, max;
	int len = strlen(s);
	
	if(s == 0 && len < 1)
	{
		return 0;
	}
	max = 0;

	for(i = 0; i < len; i++)
	{
		for(j = 0; (i - j) >= 0 && (i + j) < len; j++)
		{
			if(s[i - j] != s[i + j])
			{
				break;
			}
		}

		if(j * 2 + 1 > max)
		{
			max = j * 2 + 1;
		}

		for(j = 0; (i - j) >= 0 && (i + j + 1) < len; j++)
		{
			if(s[i - j] != s[i + j + 1])
			{
				break;
			}
		}

		if(j * 2 + 2 > max)
		{
			max = j * 2 + 2;
		}
	}

	return max;
}
