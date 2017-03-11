/*************************************************
  File name: client.c 
  Description:聊天软件客户端main函数 
**************************************************/  
#include "./main.h"  

int main(int argc, char *argv[])  
{  
	int ret;  
	char str[MAXLEN];  
	char buf[MAXLEN];  
	char buf_new[100];    
	struct message a;  
	struct sockaddr_in servaddr;       
	if(argc!=2)  
	{  
		fprintf(stderr,"Usage:%s hostname \n",argv[0]);  
		exit(1);  
	}   
	while(1)  
	{  
		if((sockfd=socket(AF_INET,SOCK_STREAM,0)) < 0)          //创建套接字，使用TCP协议  
		{  
			perror("socket:");
			exit(-1);  
		}  
		bzero(&servaddr,sizeof(struct sockaddr_in));            //清空地址结构 
		servaddr.sin_family = AF_INET;                          //使用IPV4通信域 
		servaddr.sin_port = htons(PORT);                        //端口号转换为网络字节序  
		inet_aton(argv[1],&(servaddr.sin_addr));                //接受地址
		if(ret = connect(sockfd,(struct sockaddr *)(&servaddr),sizeof(servaddr)) < 0)  //主动连接服务器 
		{  
			perror("connect:");  
			exit(1);  
		}  
		ret = Interface();     //登录界面 
		switch(ret)  
		{  
			case 1:            //登录  
				{  
					int n = 3;  
					while(n)  
					{  
						log_user(&a);  
						if(strcmp(a.msg,"hello,admin!") == 0)    //管理员登录成功 
						{  
							if(login_admin(&a) == 0)  
							{  
								return 0;  
							}  
						}  
						if(strcmp(a.msg,"login,success!") == 0)   //用户登录成功  
						{  
							if(login_success(&a) == 0)  
							{  
								return 0;  
							}  
						}  
						else                                       //登录未成功  
						{  
							n--;  
							printf("你还有 %d次机会!\n",n);  
						}  
					}  
					close(sockfd);  
					exit(3);  
					break;  
				}  
			case 2:      //注册  
				{  
					Register(&a);  
					break;  
				}  
			case 3:      //退出  
				{  
					close(sockfd);  
					printf("离开聊天室！\n");  
					break;  
				}  
			default:  
				{  
					break;  
				}  
		}  
	}  
	close(sockfd);  
	return 0;  
}
