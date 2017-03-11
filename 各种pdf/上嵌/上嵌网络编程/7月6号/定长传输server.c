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

int main(int argc,char **argv[])
{
	int listenfd,connfd;
	socklen_t client = 0;
	struct sockaddr_in cliaddr,servaddr;
	MyPDU stuData = {(0)};
	
	listenfd = socket(AF_INET,SOCK_STREAM,0);
	bzero(&servaddr,sizeof(servaddr));
	inet_aton("127.0.0.1",&(servaddr.sin_addr));
	servaddr.sin_port = htons(5678);
	
	bind(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	
	listen(listenfd,5);
	
	while(1)
	{
		client = sizeof(cliaddr);
		connfd = accept(listenfd,(struct sockaddr *)&cliaddr,&client);
		read(connfd,&stuData,sizeof(stuData));
		
			printf("Server info:\n");
			printf("student name :%s\n",(stuData.name));
			printf("student number:%d\n",(int)(stuData.number));
			printf("student sex:%c\n",stuData.sex);
			printf("student c socre:%f\n",stuData.cScore);
			printf("student math socre:%f\n",stuData.mathScore);
			printf("student chinese score:%f\n",stuData.chnScore);
		write(connfd,"OK\n",3);
		close(connfd);	
	}
	close(listenfd);
}







