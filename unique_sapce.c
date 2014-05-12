#include <stdio.h>

void unique_space(char *);
int main(void)
{
	char str[50] = "yang  peng   fuck  zhq";
	unique_space(str);
	return 0;
}

void unique_space(char *cstr)
{
	int i = 0;
	char *str = cstr;
	int len = strlen(cstr);
	//printf("%s\n", str);
	while(*str != '\0')
	{
		if(*str == ' ' && *(str + 1) == ' ')
		{
			//strcpy(str, str + 1);
			//memmove(str, str +1, strlen(str + 1));
			memcpy(str, str + 1, strlen(str + 1));
			cstr[--len] = '\0';
			printf("%s\n", cstr);
			//str--;
			continue;
		}
		//printf("%s\n", cstr);
		str++;
	}
	printf("%s\n", cstr);
}
