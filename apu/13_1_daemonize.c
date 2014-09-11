#include "apue.h"
#include <syslog.h>
#include <fcntl.h>
#include <sys/resource.h>

void daemonize(const char *cmd)
{
	int i, fd0, fd1, fd2;
	pid_t pid;
	struct rlimit r1;
	struct sigaction sa;

	//step 1
	umask(0);

	if(getrlimit(RLIMIT_NOFILE, &r1) < 0)
		exit(-1);
	
	//step 2
	if((pid = fork()) < 0)
	{
		exit(-2);
	}
	else if(pid > 0)
	{
		exit(0);
	}

	//step 3
	setsid();
	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;

	if(sigaction(SIGHUP, &sa, NULL) < 0)
		exit(-3);

	if((pid = fork()) < 0)
	{
		exit(-2);
	}
	else if(pid > 0)
	{
		exit(0);
	}	

	//step 4
	if(chdir("/") < 0)
		exit(-4);

	//step 5
	if(r1.rlim_max == RLIM_INFINITY)
		r1.rlim_max = 1000;
	for(i = 0; i < r1.rlim_max; i++)
		close(i);

	//step 6
	fd0 = open("/dev/null", O_RDWR);
	fd1 = dup(0);
	fd2 = dup(0);

	
	openlog(cmd, LOG_CONS, LOG_DAEMON);
	if(fd0 != 0 || fd1 != 1 || fd2 != 2)
	{
		syslog(LOG_ERR, "unexpected file dessriptors");
		exit(1);
	}
}


int main(void)
{
	daemonize("yangpeng");
	while(1)
		sleep(1);
	exit(0);
}
