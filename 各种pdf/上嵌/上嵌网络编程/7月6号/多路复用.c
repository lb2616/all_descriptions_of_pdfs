#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <strings.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/time.h>



int getMaxFd(int *pint,int size);//获取最大fd
void addFd(int *pint,int size,int fd);//添加fd函数
void setAllFd(int *pint,int size,fd_set *fdset);//设定集合中所有fd

int main(int argc,char **agrv[])
{
	int listenfd,connfd;
	socklen_t client;
	struct sockaddr_in cliaddr,servaddr;//客户端和服务器端的ip地址
	char buf[20]={'\0'};
	fd_set rset;//文件集合
	int maxfd;//最大文件数
	int ret;
	int clientfd[64]={0};
	int i = 0;
	
	listenfd = socket(AF_INET,SOCK_STREAM,0);
	if(listenfd<0)
	{
		perror("create socket fail\n");
		exit(-1);
	}
	memset(clientfd,0xff,sizeof(clientfd));//用-1初始化文件号
	
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	inet_aton("192.168.16.44",&servaddr.sin_addr);
	servaddr.sin_port = htons(5678);
	
	bind(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	
	listen(listenfd,5);
	maxfd = listenfd;
	for(;;)
	{
		FD_ZERO(&rset);
		FD_SET(listenfd,&rset);
		setAllFd(clientfd,64,&rset);
		maxfd = getMaxFd(clientfd,64);
		if(maxfd < listenfd)
		{
			maxfd = listenfd;
		}
		ret = select(maxfd+1,&rset,NULL,NULL,NULL);
		if(ret <= 0)
		{
			if(errno = EINTR)//如果是一个中断信号
			{
				continue;
			}
			else
			{
				break;
			}
		}
		if(FD_ISSET(listenfd,&rset))
		{
			client = sizeof(cliaddr);
			connfd = accept(listenfd,(struct sockaddr *)&cliaddr,&client);
			addFd(clientfd,64,connfd);
		}
		for(i = 0;i<64;i++)
		{
			if(clientfd[i]>0)
			{
				if(FD_ISSET(clientfd[i],&rset))
				{
					int len;
					write(1,"Server Say:",strlen("Server Say:"));
					len = read(clientfd[i],buf,20);
					if(len == 0)//信息发送失败,重新初始化文件号
					{
				    	close(clientfd[i]);
				    	clientfd[i] = -1;
				    	continue;
					}
					write(1,buf,len);
					write(clientfd[i],buf,len);
					while(len == 20 &&buf[19]!='\0')
					{
						len = read(clientfd[i],buf,20);
						write(1,buf,len);
						write(clientfd[i],buf,len);
					}
					write(1,"\n",1);
				}
			}
		}
	}
	close(listenfd);
	return 0;	
}

int getMaxFd(int *pint,int size)
{
	int max = pint[0];
	int i = 0;
	for(i = 1;i<size;i++)
	{
		if(max < pint[i])
		{
			max = pint[i];
		}
	}
	return max;
}

void addFd(int *pint,int size,int fd)
{
	int i = 0;
	for(i =0;i<size;i++)
	{
		if(-1 == pint[i])
		{
			pint[i] = fd;
			break;
		}
	}
}


void setAllFd(int *pint,int size,fd_set *fdset)
{
	int i = 0;
	for(i = 0;i<size;i++)
	{
		FD_SET(pint[i],fdset);
	}
}



















