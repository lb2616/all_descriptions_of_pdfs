#include "./client.h"

/*************************************************** 
  函数名:Interface 
  功能:登录界面 
  传入参数:无 
  返回值:无 
 ***************************************************/  
int Interface()
{  
	int iChoice;
	do
	{
		system("clear");
		printf("-----------------------------------\n");
		printf("|        欢迎进入聊天室           |\n");
  		printf("-----------------------------------\n");
		printf("|           1.登录                |\n\n");
		printf("|           2.注册                |\n\n");
		printf("|           3.退出                |\n");
		printf("-----------------------------------\n");
		printf("请选择:");  
		setbuf(stdin,NULL);  
		scanf(" %d",&iChoice);  
		setbuf(stdin,NULL);  
	}while((iChoice != 1) && (iChoice != 2) && (iChoice != 3));  
	return iChoice;  
}  

/*************************************************** 
  函数名:Register 
  功能:注册 
  传入参数:struct message *a 
  返回值:返回0 
 ***************************************************/  
int Register(struct message *a)
{
	char password_t[MAXLEN];
	do
	{
		printf("请输入用户名（10字以内）:");
		memset((*a).name,0,strlen((*a).name));
		setbuf(stdin,NULL);
		scanf("%s",(*a).name);
	}while(strlen((*a).name)>20);

	while(1)
	{
		printf("请输入密  码（20位以内）:");
		memset((*a).msg,0,strlen((*a).msg));
		setbuf(stdin,NULL);
		scanf("%s",(*a).msg);
		printf("请再输入密码（20位以内）:");
		memset(password_t,0,strlen(password_t));
		setbuf(stdin,NULL);
		scanf("%s",password_t);

		if(strcmp((*a).msg,password_t) != 0 || strlen((*a).msg)>20 || strlen(password_t)>20)
		{
			printf("密码出错！\n");
		}
		else
		{
			break;
		}
	}

	strcpy((*a).flag,"reg");
	send(sockfd,a,sizeof(*a),0);
	printf("正在注册，请稍等……\n");
	recv(sockfd,a,sizeof(*a),0);
	printf("recv the message from server:%s\n",(*a).msg);
	sleep(3);
}

/*************************************************** 
  函数名:log_user
  功能:用户登录
  传入参数:struct message *a
  返回值:无
 ***************************************************/  
void log_user(struct message *a)
{
	do
	{
		printf("请输入用户名（10字以内）:");
		memset((*a).name,0,strlen((*a).name));
		scanf("%s",(*a).name);
		strcpy(locname,(*a).name);
		printf("请输入密  码（20位以内）:");
		memset((*a).msg,0,strlen((*a).msg));
		scanf("%s",(*a).msg);  
	}while(strlen((*a).name)>20 || strlen((*a).msg)>20);
	strcpy((*a).flag,"login");
	send(sockfd,a,sizeof(*a),0);                  //向服务器发送登录信息  
	printf("正在登录，请稍等……\n");
	recv(sockfd,a,sizeof(*a),0);  
	printf("recv the message from server:%s\n",(*a).msg);
}
 
/*************************************************** 
  函数名:login_success 
  功能:登录成功进入聊天模式 
  传入参数:struct message *a 
  返回值:退出返回0，否则返回1 
 ***************************************************/  
int login_success(struct message *a)  
{  
	char str[MAXLEN];  
	char buf[MAXLEN];  
	time_t timep;  
	pthread_t pid;  
	sprintf(chat_log,"./chat_log/%s.txt",(*a).name);  
	if((fd=open(chat_log,O_RDWR|O_CREAT|O_APPEND,0777)) < 0)  
	{  
		printf("打开聊天记录失败!");  
		exit(1);  
	}  
	pthread_create(&pid,NULL,(void*)handlerecvmsg,(void *)&sockfd);   //创建接受消息线程  
	setbuf(stdin,NULL);  
	strcpy((*a).flag,"all");  
	printf("尊敬的%s你好，如需帮助请输入：.help\n",locname);  
	while(1)  
	{  
		memset((*a).msg,0,strlen((*a).msg));  
		memset(str,0,strlen(str));  
		usleep(100000);

		printf("TO %s:\n",(*a).flag);  
		setbuf(stdin,NULL);  
		scanf("%s",str);  
		if(1 == help(str))                            //提示信息    
		{  
			continue;  
		} 
 
		strcpy((*a).name,locname);  
		strcpy(buf,(*a).flag);  
		cutStr(str,(*a).flag,15,(*a).msg,MAXLEN,'$'); //调用字符切割函数    
		expression((*a).name,(*a).msg);               //表情替换函数   
		common_use_words((*a).msg);                   //常用语使用函数
  
		if(strcmp((*a).flag,"exit") == 0)  
		{  
			return 0;
		}  
		if(strcmp((*a).flag,"view") == 0)             //请求查看在线用户
		{  
			send(sockfd,a,sizeof((*a)),0);           
			strcpy((*a).flag,buf);  
			continue;  
		}  
		if(strcmp((*a).flag,"all") == 0)  
		{  
			send(sockfd,a,sizeof(*a),0);          
			continue;  
		}  
		if ((strcmp((*a).flag,"trans") == 0) && (savefilefd <=0))  
		{  
			if ((strcmp((*a).msg,"agree") == 0) && (savefilefd == 0))  
			{  
				char savefilename[MAXLEN];  
				strcpy((*a).addressee,filefromuser);  
				printf("请输入你想保存的文件名：\n");  
				do  
				{  
					setbuf(stdin,NULL);  
					scanf("%s",savefilename);  
					savefilefd = open(savefilename,O_RDWR|O_CREAT|O_EXCL,0777);  
					if(savefilefd == -1)  
					{  
						printf("文件已存在，你重新输入：\n");  
					}  
				}while(savefilefd == -1);
  
				if(savefilefd < 0)  
				{  
					printf("接收文件失败!\n");  
					savefilefd = -1;  
				}  
				else  
				{  
					strcpy((*a).msg,"agree");  
					send(sockfd,a,sizeof(*a),0);  
					printf("文件接收中……\n");  
				}  
			}  
			else  
			{  
				memset(str,0,strlen(str));  
				cutStr((*a).msg,(*a).addressee,20,str,MAXLEN,'$');  
				if (str[0] != '\0' && (*a).addressee[0] != '\0')  
				{  
					char transfileallname[22];  
					sprintf(transfileallname,"./%s",str);  
					savefilefd = open(str,O_RDWR,0666);  
					if(savefilefd < 0)  
					{  
						printf("打开文件失败!\n");  
						savefilefd = -1;  
					}  
					else  
					{  
						memset((*a).msg,0,strlen((*a).msg));  
						strcpy((*a).msg,str);  
						send(sockfd,a,sizeof(*a),0);  
					}  
				}  
				else  
				{  
					strcpy((*a).msg,"disagree");  
					strcpy((*a).name,locname);  
					strcpy((*a).addressee,filefromuser);  
					send(sockfd,a,sizeof(*a),0);  
				}  
			}  
			strcpy((*a).flag,buf);  
			continue;  
		}  
		if (strcmp((*a).flag,"trans") == 0)  
		{  
			strcpy((*a).flag,buf);  
		}  
		else  
		{  
			strcpy(buf,(*a).flag);  
			strcpy((*a).addressee,(*a).flag);  
			strcpy((*a).flag,"personal");  
			send(sockfd,a,sizeof(*a),0);             //发送私信  
			strcpy((*a).flag,buf);  
			time (&timep);  
			memset(str,0,strlen(str));  
			sprintf(str,"%s你对 %s 说: %s\n",ctime(&timep),(*a).flag,(*a).msg);  
			printf("%s",str);  
			write(fd,str,strlen(str));              //写入聊天记录文件中  
		}  
	}  
	return 1;  
}

/*************************************************** 
  函数名:help 
  功能:帮助 
  传入参数:char str[] 
  返回值:成功返回1，否则返回0 
 ***************************************************/  
int help(char str[])  
{  
	if(strcmp(str,".help") == 0)  
	{  
		printf("尊敬的 %s 用户，你好：\n",locname);  
		printf("all$hello!-------------对所有人说hello!\n");  
		printf("bill$hello!------------对bill说hello!\n");  
		printf("trans$bill$hello.txt---传文件hello.txt给bill\n");  
		printf("trans$agree------------同意接收文件\n");  
		printf("trans$disagree---------不同意接收文件\n");  
		printf("view$------------------查看在线用户\n");  
		printf("exit$------------------退出\n");                   
		return 1;  
	}  
	else  
	{  
		return 0;  
	}  
}

















