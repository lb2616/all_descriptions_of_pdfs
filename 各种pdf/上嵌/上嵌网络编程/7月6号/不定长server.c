#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<strings.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#include"chat.h"

int main(int argc,char *argv[])
{
	int listenfd,connfd;
	socklen_t client ;
	struct sockaddr_in cliaddr,servaddr;
	MyPDU *pstChatData = NULL;
	unsigned long pdulen = 0;
	
	listenfd = socket(AF_INET,SOCK_STREAM,0);
	
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	inet_aton("127.0.0.1",&(servaddr.sin_addr));
	servaddr.sin_port = htons(5678);
	
	bind(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	
	listen(listenfd,5);
	
	while(1)
	{
		client = sizeof(cliaddr);
		connfd = accept(listenfd,(struct sockaddr *)&cliaddr,&client);
		read(connfd,&pdulen,sizeof(pdulen));
		pdulen = ntohl(pdulen);
		printf("server:pdulen = %d\n",(int)pdulen);
		pstChatData = (MyPDU*)malloc(pdulen);
		if(NULL==pstChatData)
		{
			printf("server:Malloc Failed\n");
			close(connfd);
			continue;
		}	
		bzero(pstChatData,pdulen);
		pstChatData->length = pdulen;
		read(connfd,pstChatData->data,pdulen-sizeof(pstChatData->length));
		printf("server say :%s\n",pstChatData->data);
		write(connfd,"OK\n",3);
		close(connfd);	
	}
	close(listenfd);
	return 0;
}







