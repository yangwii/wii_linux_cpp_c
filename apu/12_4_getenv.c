#include <pthread.h>
#include "apue.h"

extern char ** environ;
pthread_mutex_t env_mtx;
static pthread_once_t init_done = PTHREAD_ONCE_INIT;

static void thread_init()
{
	pthread_mutexattr_t attr;

	pthread_mutexattr_init(&attr);
	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init(&env_mtx, &attr);

	pthread_mutexattr_destroy(&attr);
}

int _getenv(const char *name, char *buf, int buflen)
{
	int i, len, olen;
	
	pthread_once(&init_done, thread_init);
	len = strlen(name);
	pthread_mutex_lock(&env_mtx);

	for(i = 0; environ[i] != NULL; i++)
	{
		if((strncmp(name, environ[i], len) == 0)
					&& (environ[i][len] == '='))
		{
			olen = strlen(&environ[i][len+1]);
			if(olen >= buflen)
			{
				pthread_mutex_unlock(&env_mtx);
				return -1;	
			}
			strcpy(buf, &environ[i][len+1]);
			pthread_mutex_unlock(&env_mtx);
			return 1;
		}
	}

	pthread_mutex_unlock(&env_mtx);
	return -2;
}

int main(void)
{
	char name[10] = "LANG";
	char *val = malloc(30);
	if(_getenv(name, val, 30) == 1)
	{
		printf("%s\n", val);
	}
	else
	{
		printf("%s\n", "error");
	}

	return 0;
}
