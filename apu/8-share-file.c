#include <unistd.h>
#include <stdio.h>

#define PARENT_CONTENT "parent write\n"
#define CHILE_CONTENT "chile write\n"

int main(void)
{
	FILE *fp = fopen("8-share-file.txt", "wa");
	if(NULL == fp)
	{
		printf("open/create file error\n");
		return 1;
	}

	pid_t pid = fork();

	if(pid == 0)
	{
		fputs(CHILE_CONTENT, fp);
	}
	else if(pid > 0)
	{
		fputs(PARENT_CONTENT, fp);
	}
	else
	{
		printf("fork fail\n");
		return 2;
	}
	return 0;
}
