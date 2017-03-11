#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<strings.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include <sys/select.h>
#include <sys/time.h>

int main(int argc,char *argv[])
{
	int	sockfd;
	int 	stdinfd = 0;
	fd_set  rset;
	struct sockaddr_in	servaddr;
	int ret;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(6666);
	inet_aton("192.168.16.57", &servaddr.sin_addr);

	connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
	while(1)
	{
		FD_ZERO(&rset);
		FD_SET(stdinfd,&rset);
		FD_SET(sockfd,&rset);
		ret = select(sockfd + 1,&rset,NULL,NULL,NULL);
		if(ret <= 0)
		{
			if(errno == EINTR)
			{
				continue;
			}
			else
			{
				break;
			}
		}
		if(FD_ISSET(stdinfd,&rset))
		{
			char buf[20] = {'\0'};
			int len = 0;
			int isexit = 0;
			do
			{
				bzero(buf,20);
				fgets(buf,20,stdin);
				if(strcmp(buf,"quit\n") == 0)
				{
					isexit = 1;
					break;
				}
				len = strlen(buf);
				if(buf[len-1]=='\n')
				{
					buf[len -1] = '\0';
					write(sockfd,buf,len);
					break;
				}
				write(sockfd,buf,len);
			}while(buf[18]!='\0');
			if(isexit)
			{
				break;
			}
		}
	if(FD_ISSET(sockfd,&rset))
		{
			int len;
			char buf[20] = {'\0'};
            write(1,"Client Say:",strlen("Client Say:"));
            len = read(sockfd,buf,20);
			if(len == 0)
			{
				break;
			}
            write(1,buf,len);
            while(len == 20  && buf[19] != '\0')
            {
               	len = read(sockfd,buf,20);
                 write(1,buf,len);
            }
            write(1,"\n",1);
		}
	}
	close(sockfd);
	exit(0);
}



