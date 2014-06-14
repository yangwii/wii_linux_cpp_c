#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>

#define MAXLINE 4096
#define LISTENQ 1024

int main(int argc, char **argv)
{
	int listenfd, connfd;
	struct sockaddr_in servaddr;
	struct sockaddr_in clientaddr;
	char buff[MAXLINE];
	time_t ticks;

	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	
	memset(&servaddr, 0, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(13);

	if(bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
	{
		printf("bind failed\n");
		return 1;
	}

	if(listen(listenfd, LISTENQ) == -1)
	{
		printf("listen failed\n");
		return 4;
	}
	printf("time server start working\n");

	while(1)
	{
		if((connfd = accept(listenfd, (struct sockaddr *)NULL, NULL)) == -1)
		{
			printf("accept failed\n");
			return 2;
		}

		ticks = time(NULL);

		snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));

		if(write(connfd, buff, strlen(buff)) == -1)
		{
			printf("write failed\n");
			return 3;
		}

		//printf("clientIP --->%s\n", clientaddr.sin_addr.s_addr);
		close(connfd);
	}
	return 0;
}
