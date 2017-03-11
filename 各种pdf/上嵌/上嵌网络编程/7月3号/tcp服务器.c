#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<strings.h>
#include<arpa/inet.h>

int main(int argc,char **argv[])
{
	int listenfd = -1;
	int connfd = -1;
	socklen_t client = 0;
	struct sockaddr_in cliaddr = {0};
	struct sockaddr_in servaddr = {0};
	int ret = 0;
	char buf[20] = {'\0'};
	listenfd = socket(AF_INET,SOCK_STREAM,0);
	
	bzero(&servaddr,sizeof(servaddr));
	inet_aton("192.168.16.44",&(servaddr.sin_addr));
	servaddr.sin_port = htons(5678);
	ret = bind(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	ret = listen(listenfd,5);
	
	while(1)
	{
		client = sizeof(cliaddr);
		connfd = accept(listenfd,(struct sockaddr *)&cliaddr,&client);
		read(connfd,buf,11);
		printf("Server say :%s\n",buf);
		write(connfd,buf,11);
		close(connfd);	
	}
	close(listenfd);
}
