#include "./client.h"  

/*************************************************** 
  函数名:admin_chat 
  功能:管理员聊天功能 
  传入参数:int sockfd,struct message *a 
  返回值:退出返回0 
 ***************************************************/  
int admin_chat(int sockfd,struct message *a)    
{  
	char str[MAXLEN];  
	char buf[MAXLEN];  
	time_t timep;  
	sprintf(chat_log,"./chat_log/%s.txt",(*a).name);  
	if((fd=open(chat_log,O_RDWR|O_CREAT|O_APPEND,0777)) < 0)  
	{  
		printf("打开聊天记录失败!");  
		exit(1);  
	}  
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
		if(1 == help(str))                      //提示信息    
		{  
			continue;  
		}  
		strcpy((*a).name,locname);  
		strcpy(buf,(*a).flag);  
		cutStr(str,(*a).flag,15,(*a).msg,MAXLEN,'$');    //调用字符切割函数    
		expression((*a).name,(*a).msg);               //表情替换函数   
		common_use_words((*a).msg);                    //常用语使用函数  
		if(strcmp((*a).flag,"exit") == 0)  
		{  
			return 0;  
		}  
		if(strcmp((*a).flag,"view") == 0)             
		{  
			send(sockfd,a,sizeof((*a)),0);       //请求查看在线用户  
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
}  

/*************************************************** 
  函数名:admin_kick 
  功能:管理员踢人操作 
  传入参数:int sockfd,struct message *a 
  返回值:成功返回1，否则返回0 
 ***************************************************/  
int admin_kick(int sockfd,struct message *a)       
{  
	char str[MAXLEN];   
	do  
	{  
		printf("你想把谁踢出聊天室:\n");  
		setbuf(stdin,NULL);         //清空缓存  
		scanf("%s",str);                    
	}while(strcmp(str,"admin") == 0);                    
	if(strcmp(str,"") == 0)           //str为空  
	{  
		return 0;  
	}  
	else  
	{  
		strcpy((*a).flag,"admin_kick");            //管理员踢人标志  
		strcpy((*a).msg,str);  
		send(sockfd,a,sizeof(struct message),0);   //客户端把要求传给服务器         
	}  
	return 1;  
}  
/*************************************************** 
  函数名:admin_screen 
  功能:管理员禁言功能 
  传入参数:int sockfd,struct message *a 
  返回值:成功返回1，否则返回0 
 ***************************************************/  
int admin_screen(int sockfd,struct message *a)  
{  
	char str[MAXLEN];  
	do  
	{  
		printf("你想禁言／解禁谁:\n");  
		setbuf(stdin,NULL);  
		scanf("%s",str);  
	}while(strcmp(str,"admin") == 0);  
	if(strcmp(str,"") == 0)   
	{  
		return 0;  
	}  
	else  
	{  
		strcpy((*a).flag,"admin_screen");        //禁言标志  
		strcpy((*a).msg,str);  
		send(sockfd,a,sizeof(struct message),0);    
	}  
	return 1;  
}  
/*************************************************** 
  函数名:login_admin 
  功能:管理员登录 
  传入参数:struct message *a 
  返回值:成功返回1，否则返回0 
 ***************************************************/  
int login_admin(struct message *a)  
{  
	int iChoice;                        
	pthread_t pid;  
	memset((*a).msg,0,strlen((*a).msg));                              //清空消息  
	strcpy(chat_log,"admin");                                          //聊天记录名  
	pthread_create(&pid,NULL,(void*)handlerecvmsg,(void *)&sockfd);     //创建线程      
	while(1)  
	{  
		usleep(500000);
		do  
		{  
			printf("1.踢人  2.禁言／解禁  3.查看在线用户  4.聊天  5.退出\n");  
			printf("please input:");         
			setbuf(stdin,NULL);                                 //清空缓存  
			scanf(" %d",&iChoice);  
			system("clear");  
			setbuf(stdin,NULL);                                 //清空缓存  
		}while((iChoice != 1) && (iChoice != 2) && (iChoice != 3) && (iChoice != 4)&& (iChoice != 5));  
		switch(iChoice)  
		{  
			case 1:  
				{  
					admin_kick(sockfd,a);                 
					break;  
				}  
			case 2:  
				{  
					admin_screen(sockfd,a);         
					break;  
				}  
			case 3:  
				{  
					strcpy((*a).flag,"view");  
					send(sockfd,a,sizeof(*a),0);  
					break;  
				}  
			case 4:  
				{  
					admin_chat(sockfd,a);  
					break;  
				}  
			case 5:  
				{  
					close(sockfd);  
					return 0;  
				}  
			default:  
				{  
					break;  
				}  
		}  
	}  
	return 1;  
}
