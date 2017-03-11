#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<strings.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<errno.h>

#define BUF_SIZE 1024

int main(int argc,char *argv[])
{
	int listenfd = -1;
	int connfd = -1;
	socklen_t client = 0;
	struct sockaddr_in servaddr = {0};
	struct sockaddr_in cliaddr = {0};
	char *pbuf = NULL;
	int fd = -1;
	int len = 0;
	
	pbuf = (char*)malloc(BUF_SIZE);
	if(NULL == pbuf)
	{
		printf("Malloc failed\n");
		return 2;
	}
	bzero(pbuf,BUF_SIZE);
	listenfd = socket(AF_INET,SOCK_STREAM,0);
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	inet_aton("192.168.16.44",&(servaddr.sin_addr));
	servaddr.sin_port = htons(5678);
	
	bind(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	int ret;
	ret = listen(listenfd,5);
	if(ret<0)
	{
		perror("listen :");
		return -1;
	}
	while(1)
	{
		bzero(pbuf,BUF_SIZE);
		client = sizeof(cliaddr);
		connfd = accept(listenfd,(struct sockaddr *)&cliaddr,&client);
		if(connfd<0)
		{
			perror("accept fail :");
			exit(-1);
		}
		int size;
		size = read(connfd,pbuf,BUF_SIZE);
		if(size<0)
		{
			perror("read fail :");
			exit(-1);
		}
		len = strlen(pbuf);
		fd = open(pbuf,O_RDONLY);
		if(fd<0)
		{
			sprintf(pbuf+len,"%s","open failed\n");
			len = strlen(pbuf);
			write(connfd,pbuf,len);
		}
		else
		{
			bzero(pbuf,BUF_SIZE);
			while(len = read(fd,pbuf,BUF_SIZE)>0)
			{
				write(connfd,pbuf,len);
			}
			close(fd);
		}
		close(connfd);
	}
	free(pbuf);
	close(listenfd);
	return 0;
}








