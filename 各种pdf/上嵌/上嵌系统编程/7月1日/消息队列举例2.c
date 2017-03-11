#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<stdlib.h>

#define BUFSZ 512
#define TYPE 100
struct msgbuf
{
	long mtype;
	char mtext[BUFSZ];
};

int main()
{
	int qid,len;
	key_t key;
	struct msgbuf msg;
	
	if((key = ftok("/tmp",'a'))==-1)
	{
		perror("ftok");
		exit(1);
	}
	//创建消息队列
	if((qid = msgget(key,IPC_CREAT|0666))==-1)
	{
		perror("msgget");
		exit(-1);
	}
	printf("opened queue %d\n",qid);
	puts("Please enter the message to queue:");
	
	if((fgets((&msg)->mtext,BUFSZ,stdin))==NULL)
	{
		puts("no message");
		exit(-1);
	}
	msg.mtype = TYPE;
	len = strlen(msg.mtext) + 1;
	
	//添加消息到消息队列
	if(msgsnd(qid,&msg,len,0)<0)
	{
		perror("msgsnd");
		exit(-1);
	}
	
	//从消息对垒读取消息
	if(msgrcv(qid,&msg,BUFSZ,0,0)<0)
	{
		perror("msgrcv");
		exit(-1);
	}
	printf("message is : %s\n",(&msg)->mtext);
	//从系统中删除消息队列
	
	if(msgctl(qid,IPC_RMID,NULL)<0)
	{
		perror("msgctl");
		exit(1);
	}
	return 0;
}






