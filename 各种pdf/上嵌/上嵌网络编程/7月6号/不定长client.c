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

#define CHAT_CONTENT "fjaohgahgjs[hnphisz[f'bugpsogh;a"

int main(int argc,char *argv[])
{
	int sockfd;
	struct sockaddr_in servaddr;
	MyPDU *pstChatData;
	char buf[8]={'\0'};
	unsigned long size = 0;
	size = sizeof(MyPDU)-4+strlen(CHAT_CONTENT)+1;
	pstChatData = (MyPDU*)malloc(size);
	if(NULL==pstChatData)
	{
		printf("malloc failed\n");
		return 1;
	}
	bzero(pstChatData,size);
	pstChatData->length = htonl(size);
	strcpy(pstChatData->data,CHAT_CONTENT);
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port= htons(5678);
	inet_aton("127.0.0.1",&servaddr.sin_addr);
	
	connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	write(sockfd,pstChatData,pstChatData->length);
	read(sockfd,buf,3);
	printf("Client say:%s",buf);
	close(sockfd);
	exit(0);
}





