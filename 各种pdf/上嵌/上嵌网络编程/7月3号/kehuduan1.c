#include<stdio.h>
#include<sys/socket.h>
#include<strings.h>
#include<string.h>
#include<arpa/inet.h>

int main(int argc,char *argv[])
{
	int sockfd,i=1;
	struct sockaddr_in servaddr;
	char buf[50] = {'\0'},newbuf[200];
	sockfd = socket(AF_INET,SOCK_DGRAM,0);
	bzero(&servaddr,sizeof(servaddr));
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(5678);
	inet_aton("192.168.16.57",&servaddr.sin_addr);
	while(strcmp(buf,"bye")!=0)
	{
	printf("请输入信息:");
	scanf("%s",buf);
	strcpy(newbuf,"client2:");
	strcat(newbuf,buf);
	write(sockfd,newbuf,sizeof(newbuf));
	read(sockfd,buf,sizeof(buf));
	printf("Client say : %s\n",buf);
	}
	close(sockfd);
	return 0;
}


