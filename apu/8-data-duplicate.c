#include <unistd.h>
#include <stdio.h>

int global = 0;
int main(void)
{
	int local = 0;
	printf("init global = %d, local = %d\n", global, local);

	pid_t child_id = fork();
	if(child_id == 0)
	{
		global++;
		local++;

		printf("child running, global = %d, local = %d\n", global, local);
	}
	else if(child_id > 0)
	{
		global++;
		local++;
		printf("Process running, global = %d, local = %d\n", global, local);
	}
	else
	{
		printf("fork error\n");
	}
	return 0;
}
