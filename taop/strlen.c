#include <stdio.h>

int _strlen(char *s);
void printStrReverse(char *s);
void __strlen(char *s, int len);

int main(int argc, char **argv)
{
	printf("%d\n", _strlen(argv[1]));	
	__strlen(argv[1], 0);	
	printStrReverse(argv[1]);
	printf("\n");
	//char s[] = "yangpeng";
	//_strlen(s);
	return 0;
}

int _strlen(char *s)
{
	if(*s == '\0' || s == NULL)
		return 0;	
	else
		return 1 + _strlen(s + 1);//不能写成_strlen(s++);
}

void __strlen(char *s, int len)
{
	if(*s == '\0' || s == NULL)
	{
		printf("%d\n", len);
		return;
	}
	__strlen(s + 1, len + 1);//不能写成_strlen(s++); 不然会core dump
}

void printStrReverse(char *s)
{
	if(s == NULL || *s == '\0')
	{
		return;
	}
	else
	{
		printStrReverse(s + 1);
		printf("%c", *s);
	}
}
