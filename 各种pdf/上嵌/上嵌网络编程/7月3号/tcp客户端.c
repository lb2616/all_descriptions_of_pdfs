#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/socket.h>
#include<strings.h>
#include<arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc,char *argv[])
{
	int sockfd;
	struct sockaddr_in servaddr;
	unsigned short servport;
	char *pbuf;
	int len;
	
	if(argc != 3)
	{
		printf("usage:./client 127.0.0.1 5678\n");
		return 1;
	}
	pbuf = (char *)malloc(BUF_SIZE);
	if(NULL == pbuf)
	{
		printf("Malloc failed\n");
		return 2;
	}
	bzero(pbuf,BUF_SIZE);
	sscanf(argv[2],"%d",(int*)&servport);
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{
		printf("套接字错误!\n");
	}
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(servport);
	inet_aton(argv[1],&servaddr.sin_addr);
	
	connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	fgets(pbuf,BUF_SIZE,stdin);
	if(pbuf[len-1]=='\n')
	{
		pbuf[len-1]='\0';
		len --;
	}
	write(sockfd,pbuf,len);
	bzero(pbuf,BUF_SIZE);
	while(len = read(sockfd,pbuf,BUF_SIZE)>0)
	{
		write(1,pbuf,len);
	}
	close(sockfd);
	free(pbuf);
	return 0;
	
}











