/*
1.设定一个结构体:
2.process1;
*/

#include "fifo.h"
int main()
{
	NETMSG *msg;
	int mf;
	int ret;
	if(access(FIFO,F_OK)<0)
	{
		mf=mkfifo(FIFO,0777);
		if(mf<0)
		{
			perror("fifo fail:");
			exit(-1);
		}
	}
	mf = open(FIFO,O_RDONLY);
	if(mf<0)
	{
		perror("open fail:");
		return -1;
	}
	msg=(NETMSG *)malloc(sizeof(NETMSG));
	
	ret = read(mf,msg,sizeof(msg));
	if(ret<0)
	{
		perror("write fail");
		exit(-1);
	}
	printf("IP address : %s \n",msg->address);
	printf("the port %d \n",msg->port);
	printf("The message is %s\n",msg->msg);
	close(mf);
}









