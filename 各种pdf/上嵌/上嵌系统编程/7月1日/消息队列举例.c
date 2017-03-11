#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

struct stu
{
	int id;
	char name[32];
};

struct msgbuf
{
	long mtype;
	struct stu s;
};

int main()
{
	int msgid;
	key_t key = 1234;
	//1.创建消息队列
	msgid = msgget(key,IPC_CREAT |0644);
	struct msgbuf msg;
	msg.mtype = 1;//设置消息类型,必须>0
	msg.s.id = 1;
	strcpy(msg.s.name,"张三");
	//2.往消息队列发送消息
	msgsnd(msgid,&msg,sizeof(struct stu),IPC_NOWAIT);
	//3.从消息队列里面接受消息
	memset(&msg,0,sizeof(msg));
	//1为消息类型
	msgrcv(msgid,&msg,sizeof(struct stu),1,IPC_NOWAIT);
	printf("msg:[id= %d ,name = %s]\n",msg.s.id,msg.s.name);
	//4.删除消息队列
	msgctl(msgid,IPC_RMID,NULL);
	return 0;
}



