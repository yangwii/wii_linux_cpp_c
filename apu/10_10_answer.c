#include "apue.h"

int main(void)
{
	int i = 0;
	time_t t;
	for(; ;)
	{
		i++;
		if(i%5 == 0)
		{
			time(&t);
			struct tm* _t = localtime(&t);
			printf("%d\n", _t->tm_sec);	
		}
		sleep(60);
	}
	return 0;
}
