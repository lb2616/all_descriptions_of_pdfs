#include "./client.h"  

/*************************************************** 
  函数名:handlerecvmsg 
  功能:消息接收 
  传入参数:int *sockfd 
  返回值:无 
 ***************************************************/  
void handlerecvmsg(int *sockfd)  
{  
	int connfd = *sockfd;  
	int nread;  
	char buf[1024];  
	char str[1024];  
	struct message recvmsg;  
	time_t timep;                              //显示当前时间  
	if((fd=open(chat_log,O_RDWR|O_CREAT|O_APPEND,0777)) < 0)          //创建聊天记录文件      
	{  
		printf("打开聊天记录失败!");  
		exit(1);  
	}  
	while(1)  
	{  
		nread = recv(connfd,&recvmsg,sizeof(struct message),0);    //接受文件       
		if(nread == 0)  
		{  
			printf("You have detached from the server!\n");       
			close(fd);  
			close(connfd);  
			exit(0);  
		}  
		else if (strcmp(recvmsg.flag,"all") == 0)             //接受群发信息  
		{  
			time (&timep);  
			memset(str,0,strlen(str));  
			sprintf(str,"%s%s 对大家说: %s\n",ctime(&timep),recvmsg.name,recvmsg.msg);  
			printf("%s",str);  
			write(fd,str,strlen(str));                          //聊天信息写入文件  
		}  
		else if (strcmp(recvmsg.flag,"personal") == 0)         //接受私信   
		{  
			time (&timep);  
			memset(str,0,strlen(str));  
			sprintf(str,"%s%s 对你说: %s\n",ctime(&timep),recvmsg.name,recvmsg.msg);  
			printf("%s",str);  
			write(fd,str,strlen(str));                         //保存聊天记录  
		}  
		else if (strcmp(recvmsg.flag,"sermsg") == 0)          //系统提示信息  
		{  
			time (&timep);  
			memset(str,0,strlen(str));  
			sprintf(str,"%s系统信息: %s\n",ctime(&timep),recvmsg.msg);  
			printf("%s",str);  
			write(fd,str,strlen(str));  
			continue;  
		}  
		else if (strcmp(recvmsg.flag,"view") == 0)       //收到查看在线用户标志  
		{  
			time (&timep);  
			memset(str,0,strlen(str));  
			sprintf(str,"%s在线用户:\n%s\n",ctime(&timep),recvmsg.msg);  
			printf("%s",str);  
			continue;  
		}  
		else if (strcmp(recvmsg.flag,"trans") == 0)          //传输文件标志  
		{  
			pthread_t pid;  
			if (strcmp(recvmsg.msg,"agree") == 0)          //同意接受文件标志  
			{  
				strcpy(filefromname,recvmsg.name);  
				printf("文件传送中……\n");  
				//创建线程发送文件  
				pthread_create(&pid,NULL,(void *)handlesendfile,NULL);     //创建发送文件线程  
			}  
			else if(strcmp(recvmsg.msg,"disagree") == 0)  
			{  
				printf("对方拒绝接收文件\n");  
				close(savefilefd);  
				savefilefd = -1;  
			}  
			else if(strcmp(recvmsg.msg,"noexist") == 0)  
			{  
				printf("对不起，该客户端不存在\n");  
				close(savefilefd);  
				savefilefd = -1;  
			}  
			else  
			{  
				strcpy(filefromuser,recvmsg.name);  
				strcpy(filefromname,recvmsg.msg);  
				printf("%s向你传文件%s,是否同意接受?\n同意请输入：trans$agree\t不同意请输入：trans$disagree\n",recvmsg.name,recvmsg.msg);  
				savefilefd = 0;  
			}  
			continue;  
		}  
		else if(strcmp(recvmsg.flag,"transf") == 0)                 
		{  
			pthread_t pid_transf;  
			pthread_create(&pid_transf,NULL,(void *)handlerecvfile,&recvmsg); //创建文件传输线程  
			pthread_join(pid_transf,NULL);            
			continue;  
		}  
		else  
		{  
			if(strcmp(recvmsg.flag,"") == 0)  
			{  
				continue;  
			}  
		}  
	}  
}

/*************************************************** 
  函数名:handlerecvfile 
  功能:文件接收 
  传入参数:struct message *msg 
  返回值:无 
 ***************************************************/  
void handlerecvfile(struct message *msg)  
{  
	int n;  
	struct message recvmsg = *msg;  
	if(strcmp(recvmsg.msg,"end$") == 0)           //接收标志为end$  
	{  
		printf("文件传输结束!\n");  
		close(savefilefd);  
		savefilefd = -1;  
		return ;  
	}  
	else  
	{  
		pthread_mutex_lock(&lock);           //上锁  
		n=write(savefilefd,recvmsg.msg,recvmsg.size); //写入文件，保存聊天记录  
		pthread_mutex_unlock(&lock);   //解琐  
		if(n < recvmsg.size && n > 0)  
		{  
			printf("接收文件出错!\n");  
			return ;  
		}  
	}  
	return ;  
}  

/*************************************************** 
  函数名:handlesendfile 
  功能:文件传输 
  传入参数:无 
  返回值:无 
 ***************************************************/  
void handlesendfile()  
{  

	struct message filedata;  
	do  
	{  
		memset(filedata.msg,0,sizeof(filedata.msg));            //清空消息缓存      
		filedata.size =read(savefilefd,filedata.msg,1000);        
		strcpy(filedata.flag,"transf");  
		strcpy(filedata.addressee,filefromname);  
		if (filedata.size == 0)  
		{  
			printf("文件传输完毕!\n");  
			strcpy(filedata.msg,"end$");  
			send(sockfd,&filedata,sizeof(struct message),0);     //向服务器发送结束标志  
		}  
		else if (filedata.size > 0)  
		{  
			send(sockfd,&filedata,sizeof(struct message),0);     //发送文件数据      
			usleep(100000);                
		}  
		else  
		{  
			printf("读取文件失败,文件传输中止\n");  
			break;  
		}  
	}while(filedata.size > 0);  
	close(savefilefd);  
	savefilefd = -1 ;  
}


/*************************************************** 
  函数名:cutStr 
  功能:将字符串str在字符c处分割，前后两段 
  分别赋给left和right，left最大长度为n，str最大 
  长度为max 
  传入参数:char str[],char left[], int n, char right[],int max, char c 
  返回值:无 
 ***************************************************/  
void cutStr(char str[],char left[], int n, char right[],int max, char c)  
{  
	int i,k,j;  
	for(i = 0 ; i < n ;i++)  
	{  
		if(str[i] == c)                             //c为str的分割符  
			break;  
	}  
	if(i == n)  
	{  
		i = -1;  
	}  
	else  
	{  
		memset(left,0,strlen(left));  
		for(k = 0 ; k < i ; k++)  
		{  
			left[k] = str[k];         //c左边的字符串赋给left[]   
		}  
	}  
	for(j = i+1 ; j < max;j++)  
	{  
		if(str[j] == '\0')  
			break;  
		right[j-i-1] = str[j];     //c右边的字符串给right[]  
	}  
	left[i] = '\0';  
	if(j < max)  
	{  
		right[j-i-1] = '\0';  
	}     
	else  
	{  
		right[max] = '\0';  
	}  
}  

/*************************************************** 
  函数名:common_use_words 
  功能:常用语替换 
  传入参数:char msg[] 
  返回值:无 
 ***************************************************/  
void common_use_words(char msg[])  
{  
	int i=0,j=0;  
	char common[MAXLEN];  
	char tmp[MAXLEN];  
	if(msg[0] == '/')  
	{  
		strcpy(tmp,msg);  
		memset(msg,0,strlen(msg));  
		for(i=1;i<MAXLEN;i++)  
		{  
			if(tmp[i] != '/')  
			{  
				msg[i-1] = tmp[i];  
			}  
			else  
			{  
				break;  
			}  
		}  
		msg[i-1] = ',';  
		msg[i] = '\0';  
		i++;  
		for(j=0;i<MAXLEN;i++,j++)  
		{  
			if(tmp[i] != '\0')  
			{  
				common[j] = tmp[i];  
			}  
			else  
			{  
				break;  
			}  
		}  
		common[j] = '\0';  
		if(strcmp(common,"welcome") == 0)  
		{  
			strcat(msg,"欢迎来到我们的聊天室^_^");         //连接字符串  
			return ;  
		}  
		strcat(msg,common);  

	}  
}  
/*************************************************** 
  函数名:expression 
  功能:常用表情替换 
  传入参数:char name[],char msg[],int m 
  返回值:无 
 ***************************************************/  
void expression(char name[],char msg[])  
{  
	if(strcmp(msg,":)") == 0)  
	{  
		sprintf(msg,"%s 做了个笑脸!",name);  
	}  
	if(strcmp(msg,":(") == 0)  
	{  
		sprintf(msg,"%s 表情很沮丧!",name);  
	}  
	if(strcmp(msg,"囧") == 0)  
	{  
		sprintf(msg,"%s 表情很囧!",name);  
	}  
	if(strcmp(msg,"哈哈") == 0)  
	{  
		sprintf(msg,"哈哈 ^_^");  
	}  
	if(strcmp(msg,"汗") == 0)  
	{  
		sprintf(msg,"~_~|||");  
	}  
	if(strcmp(msg,"晕") == 0)  
	{  
		sprintf(msg,"＠_＠");  
	}  
}














