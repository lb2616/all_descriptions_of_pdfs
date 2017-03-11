#include<stdio.h>
#include<sys/socket.h>
#include<strings.h>
#include<arpa/inet.h>

int main(int argc,char *argv[])
{
	int sockfd,i=1;
	struct sockaddr_in servaddr;
	char buf[50] = {'\0'};
	sockfd = socket(AF_INET,SOCK_DGRAM,0);
	bzero(&servaddr,sizeof(servaddr));
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(5678);
	inet_aton("192.168.16.44",&servaddr.sin_addr);
	for(;1;)
	{
	printf("请输入信息:");
	gets(buf);
	if(0==strcmp(buf,"q"));
		break;
	sendto(sockfd,buf,50,0,(struct sockaddr*)&servaddr,sizeof(servaddr));
	recvfrom(sockfd,buf,50,0,NULL,NULL);
	printf("Client say : %s\n",buf);
	}
	close(sockfd);
	return 0;
}


