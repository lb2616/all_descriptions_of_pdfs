#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<strings.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#include"stu.h"

int main(int argc,char *argv[])
{
	int sockfd;
	struct sockaddr_in servaddr;
	MyPDU stuData;
	char buf[8]={'\0'};
	
	bzero(&stuData,sizeof(stuData));
	stuData.cScore=91.5;
	stuData.mathScore= 89.0;
	stuData.chnScore=92.5;
	strcpy(stuData.name,"ZhangSan");
	stuData.number=10;
	stuData.sex= 'F';
	
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port= htons(5678);
	inet_aton("127.0.0.1",&servaddr.sin_addr);
	
	connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	write(sockfd,&stuData,sizeof(stuData));
	read(sockfd,buf,3);
	printf("Client say:%s",buf);
	close(sockfd);
	exit(0);
}





