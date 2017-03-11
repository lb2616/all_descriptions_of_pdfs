#include"headfile.h"

int main(int argc, char **argv)
{	
	int serverfd;
	socklen_t client;
	struct sockaddr_in cliaddr,servaddr;
	char buf[50]={'\0'};
	serverfd = socket(AF_INET,SOCK_DGRAM,0);
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	inet_aton("192.168.16.44",&(servaddr.sin_addr));
	servaddr.sin_port = htons(5678);
	 
	bind(serverfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	
	while(1)
	{
		client = sizeof(cliaddr);
		recvfrom(serverfd,buf,50,0,(struct sockaddr *)&cliaddr,&client);
		printf("Server say :%s\n",buf);
		sendto(serverfd,buf,50,0,(struct sockaddr *)&cliaddr,client);
	}
	close(serverfd);
	return 0;
}

