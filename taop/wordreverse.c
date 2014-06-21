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
	reversestr(s, 0, len - 1);//先将整个字符串反转
	printf("%s\n", s);
	
	//调整字符串
	s[len] = ' ';
	s[len + 1] = '\0';
	
	//每当遇到一个空格时，就将这个单词反转
	for(int i = 0, j = i; i < strlen(s); i++)
	{
		if(s[i] == ' ')
		{
			reversestr(s, j, i - 1);
			j = i+1;
		}
	}
	
	//将字符串恢复
	s[len] = '\0';
}
