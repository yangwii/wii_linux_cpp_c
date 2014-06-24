#include <stdio.h>
#include <string.h>

void rgb(char *s);

int main(int argc, char *argv[])
{
	char s[] = "RBGBGRBBGRBGRGBGRGBGRG";
	printf("%s\n", s);
	rgb(s);
	printf("%s\n", s);
	return 0;
}
/*
*当cur指向R时，与begin指针交换元素，cru++，begin++
*当cur指向G时，不做任何交换，cur++，其他指针不变
*当cur指向B时，与end指针交换元素，cur不变，end--
*/
void rgb(char *s)
{
	char *cur = s;
	char *begin = s;
	char *end = s + strlen(s) - 1;

	char tmp;
	while(cur < end)
	{
		if(*cur == 'R')
		{
			tmp = *cur;
			*cur = *begin;
			*begin = tmp;
		
			cur++;
			begin++;
		}
		else if(*cur == 'G')
		{
			cur++;
		}
		else
		{
			tmp = *cur;
			*cur = *end;
			*end = tmp;

			end--;
		}
	}
}
