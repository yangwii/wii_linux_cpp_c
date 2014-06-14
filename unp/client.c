#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAXLINE 4096

int main(int argc, char **argv)
{
	int sockfd, n;
	char recvline[MAXLINE + 1];

	struct sockaddr_in servaddr;
	if(argc != 2)
	{
		printf("usage:a.out <IPaddress>\n");
		return 1;
	}

	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		printf("socket failed\n");
		return 2;
	}

	memset(&servaddr, 0, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(13);

	if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) == -1)
	{
		printf("pton failed:%s\n", argv[1]);
		return 3;
	}
	if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
	{
		printf("conn failed\n");
		return 4;
	}

	while((n = read(sockfd, recvline, MAXLINE)) > 0)
	{
		recvline[n] = '\0';
		if(fputs(recvline, stdout) == EOF)
		{
			printf("fputs failed\n");
			return 5;
		}
	}
	return 0;
}
