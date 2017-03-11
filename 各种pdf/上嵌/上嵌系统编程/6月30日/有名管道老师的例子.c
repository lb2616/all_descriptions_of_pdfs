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
		mf=mfifo(FIFO,0777);
		if(mf<0)
		{
			perror("fifo fail:");
			exit(-1);
		}
	}
	mf = open(FIFO,O_WRONLY);
	if(mf<0)
	{
		perror("open fail:");
		return -1;
	}
	msg=(NETMSG *)malloc(sizeof(NETMSG));
	strcpy(msg->address,"192.168.1.234");
	msg->port=50001;
	strcpy(msg->msg,"we are studying system program");
	ret = write(mf,msg,sizeof(msg));
	if(ret<0)
	{
		perror("write fail");
		exit(-1);
	}
	close(mf);
}









