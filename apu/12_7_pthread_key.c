#include <pthread.h>
#include "apue.h"

static pthread_key_t key;
static pthread_once_t init_done = PTHREAD_ONCE_INIT;
pthread_mutex_t env_mtx = PTHREAD_MUTEX_INITIALIZER;

extern char ** environ;

static void thread_init(void)
{
	pthread_key_create(&key, free);
}

char* _getenv(const char *name)
{
	int i, len;
	char *envbuf;
	pthread_once(&init_done, thread_init);
	pthread_mutex_lock(&env_mtx);
	envbuf = (char *)pthread_getspecific(key);
	if(envbuf == NULL)
	{
		envbuf = malloc(50);
		if(NULL == envbuf)
		{
			pthread_mutex_unlock(&env_mtx);
			return NULL;
		}
		pthread_setspecific(key, envbuf);
	}

	len = strlen(name);
	for(i = 0; environ[i] != NULL; i++)
	{
		if((strncmp(name, environ[i], len) == 0 
					&& environ[i][len] == '='))
		{
			strcpy(envbuf, &environ[i][len+1]);
			pthread_mutex_unlock(&env_mtx);
			return envbuf;
		}
	}
	pthread_mutex_unlock(&env_mtx);
	return NULL;
}

int main(void)
{
	char name[20] = "HOME";
	char *value = _getenv(name);
	printf("%s\n", value);

	return 0;
}
