
#include"server.h"


int getMaxFd(int * pint,int size)
{
	int max = pint[0];
	int i = 0;
	for(i=1;i < size;i++)
	{
		if(max < pint[i])
		{
			max = pint[i];
		}
	}
	return max;
}

void addFd(int * pint,int size,int fd)
{
	int i = 0;
	for(i = 0; i < size;i++)
	{
		if(-1 == pint[i])
		{
			pint[i] = fd;
			break;
		}
	}	
}
void setAllFd(int * pint,int size,fd_set * fdset)
{
	int i = 0;
	for(i = 0; i < size;i++)
	{
		if(-1 != pint[i])
		{
			FD_SET(pint[i],fdset);
		}
	}	
	
}


int overlap(struct message meag)
{   
   
    LNODE *p=LHead.next;
    while(p!=NULL)
    {    
      
        if(strcmp(p->data.name,meag.name)==0)
        {  
         
                return 1;
        } 
        p=p->next;        
    }
    return 0 ;
}

//获取系统时间
void systemtime(USER user)
{
	
	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime( &rawtime );
	sprintf(user.regtime,"%d/%d/%d %d:%d:%d\n",timeinfo->tm_year+1900,timeinfo->tm_mon+1,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec);
}

//读文件到链表的子函数,传递的参数是文件名
STNODE * readfiletolist(char filename[30])
{
	STNODE *head=(STNODE *)malloc(sizeof(STNODE));
	head->next==NULL;
	USER client;
	FILE *file=fopen(filename,"rt");
    if(file==NULL)
    {
        printf("打开文件%s出错！\n",filename);
        return;
    }
    while((fread(&client,sizeof(USER),1,file))==1)//利用尾插法将文件中读取的信息临时存储在链表中
    {
            STNODE *p=(STNODE *)malloc(sizeof(STNODE));//创建一个新结点p
            STNODE *tmp=head;
            while(tmp->next!=NULL)//将指针移动到链表的尾部，即最后一个元素的地方
                tmp=tmp->next;
            tmp->next=p;
            p->next=NULL;
            p->user=client;
    }
    	    fclose(file);
    		return head;
}

//尾插法添加注册的人员信息
STNODE * insert(STNODE *head,USER user)
{
	STNODE *tmp=head;
	STNODE *p=(STNODE *)malloc(sizeof(STNODE));//创建一个新结点p
    while(tmp->next!=NULL)//将指针移动到链表的尾部，即最后一个元素的地方
    	tmp=tmp->next;
    tmp->next=p;
    p->next=NULL;
    p->user=user;
}

//销毁链表---砍头法
void DestroyLinklist(STNODE *head)
{
    STNODE *q=(STNODE *)malloc(sizeof (STNODE));
    q=head->next;
    while(q!=NULL)
    {
    	head->next=q->next;
    	free(q);
    	q=head->next;
     } 
}

//保存函数
void save(STNODE *head,char filename[30])
{
	FILE *file;
	STNODE *p=head->next;
	file=fopen(filename,"wt");
	if(file == NULL)
	{
		printf("文件%s打开错误!!\n",filename);
		return;
	}
    while(p!=NULL)  //因为是以w的形式打开的文件，所以不论是否修改，都要重写文件
    {
         fwrite(&(p->user),sizeof(USER),1,file);
         p=p->next;printf("1111\n");printf("%s",p->user.name);
    }
}

//自动生成注册用户的ID编号
int readlinklistID(STNODE *head)
{
    STNODE *p=head->next;
    int MaxID=10000;
    if(p== NULL)
    	return MaxID;
    while(p!=NULL)
    {	
    	if(p->user.ID>MaxID)
    		MaxID=p->user.ID;
    	p=p->next;	
    }
    MaxID=MaxID+1;
    printf("%d\n",MaxID);
    return MaxID;
 }

void getlocalip(char* outip)
{
	int i=0;
	int sockfd;
	struct ifconf ifconf;
	char buf[512];
	struct ifreq *ifreq;
	char* ip;
	//初始化ifconf
	ifconf.ifc_len = 512;
	ifconf.ifc_buf = buf;
	if((sockfd = socket(AF_INET, SOCK_DGRAM, 0))<0)
	{
		return ;
	}
	ioctl(sockfd, SIOCGIFCONF, &ifconf);    //获取所有接口信息
	close(sockfd);
	//接下来一个一个的获取IP地址
	ifreq = (struct ifreq*)buf;
	for(i=(ifconf.ifc_len/sizeof(struct ifreq)); i>0; i--)
	{
		ip = inet_ntoa(((struct sockaddr_in*)&(ifreq->ifr_addr))->sin_addr);
		if(strcmp(ip,"127.0.0.1")==0)  //排除127.0.0.1，继续下一个
		{
			ifreq++;
			continue;
		}
		strcpy(outip,ip);
		return;
	}
	return ;
}


int login(struct message *meag,clientinf *clientNode)
{
    int i;
    char buf[MAXLINE];
    i=login_check(meag);
    if(i==0)
    {
        printf("manager: admin login success!");
        strcpy((*meag).msg,"hello,admin!");
        insertend(clientNode);
        write((*clientNode).decr,meag,sizeof(struct message));
    }
    else if(i==1)
    {
        printf("%s Login success!\n",(*meag).name);
        memset((*meag).msg,0,strlen((*meag).msg));
        strcpy((*meag).msg,"login,success!");
        strcpy((*clientNode).name,(*meag).name);
        insertend(clientNode);
        write((*clientNode).decr,meag,sizeof(struct message));
        
        LNODE *L=LHead.next;
        strcpy((*meag).flag,"sermsg");
        sprintf((*meag).msg,"Welcome %s into the chatromm!",(*meag).name);
        while(L!=NULL)
        {
            write(L->data.decr,meag,sizeof(struct message));
            L=L->next;
        }
    }
    else
    {
        printf("%s Login failed!\n",(*meag).name);
        strcpy((*meag).msg,"login failed!");
        write((*clientNode).decr,meag,sizeof(struct message));
    }
}


int login_check(struct message *meag)
{
    //DestroyLinklist();
    STNODE *head;
    head=readfiletolist("personinf1.txt");
    CoverBookNode();
    STNODE *L=head->next;
   /* if( strcmp((*meag).name,"admin")==0)
    {
        while(p!=NULL)
        {    
       
            if(strcmp(p->user.name,"admin")==0)
             
                if(strcmp(p->user.passwd,(*meag).msg)==0)
                  
                    return 0;
        
            p=p->next;        
        }
    }*/
   // List *L=Head.next;
    while(L!=NULL)
    {    
   
       if(strcmp(L->user.name,(*meag).name)==0)
        { 
            if(strcmp(L->user.passwd,(*meag).msg)==0)
            {    
                return 1;
               
            }
        }
        
        L=L->next;        
    }
    return;
}

void CoverBookNode()
{
     List *p=Head.next;
     while(p!=NULL)
     {    
         printf("%-5s %-5s \n",
                 p->user.name,
                 p->user.passwd);
         p=p->next;
     }
     printf("\n");
     return;
}

int insertend(clientinf *clientNode)
{
    LNODE *pnode=malloc(sizeof(LNODE));
    pnode->data=(*clientNode);
    pnode->next=NULL;
   
    pnode->next=LHead.next;
    LHead.next=pnode;
   
    return;
} 

int reg(struct message *meag,clientinf *clientNode)
{
    int i;
    char buf[MAXLINE];
    i=reg_check(meag);
    if(i==1)
    {
        
        printf("%s   register success!\n",(*meag).name);
        strcpy((*meag).msg,"register successs!");
        strcpy((*clientNode).name,(*meag).name);
        write((*clientNode).decr,meag,sizeof(struct message));
    }
    else
    {
        printf("%s  register failed!\n",(*meag).name);
        strcpy((*meag).msg,"register failed!");
        write((*clientNode).decr,meag,sizeof(struct message));
    }
}

int reg_check(struct message *meag)
{
    if(strlen(meag->name)>20 || strlen(meag->msg)>20)
        return 0;
    STNODE *head;
    head=readfiletolist("personinf1.txt");
    STNODE *p=head->next;
    while(p!=NULL)
    {    
        if(strcmp(p->user.name,meag->name)==0)
        {
        		printf("用户名已存在!\n");
                return 0;
        } 
        p=p->next;        
    }
    USER user;
    strcpy(user.name,meag->name);
    strcpy(user.passwd,meag->msg);
    systemtime(user);
    user.ID=readlinklistID(head);//自动生成编号ID
    
    head=insert(head,user);           //将注册成功的信息加入链表
    
    save(head,"personinf1.txt");  //保存
    
   // DestroyLinklist(head);
    return 1;
}  

/*int insert(User user)
{
    List *pnode=malloc(sizeof(LNODE));
    pnode->user=user;
    pnode->next=NULL;
   
    pnode->next=Head.next;
    Head.next=pnode;
    
    return;
} */
 /*         
void Readfiletolinklist()
{
    FILE *fp;
    User user;
    List *p=NULL;
    fp=fopen("personinf.txt","rb");
    if(fp==NULL)
    {
        printf("读取文件出错！！\n");
        exit(0);
    }
    else
    {
       
        while((fread(&user,sizeof(struct _User),1,fp))==1)
        // 利用尾插法将文件中读取的信息临时存储在链表当中
        {
            
            List *p=malloc(sizeof(struct _List));
            //1-1创建一个新结点p
            if(Head.next==NULL)
            {
                Head.next=p;
                p->next=NULL;
                p->user=user;
            }
            else
            {
                List *tmp=&Head;
          
                while(tmp->next!=NULL)
                    tmp=tmp->next;
                tmp->next=p;
                p->next=NULL;
                p->user=user;
            }
 
        }
        free(p);
    }
  
    fclose(fp);
    fp=NULL;
    return ;
    
}

void Readlinklisttofile()
{
    FILE *fp;
    List head=Head;
    fp=fopen("personinf.txt","wb");
    while(head.next!=NULL)  
    {
        fwrite(&head.next->user,sizeof(struct _User),1,fp);
        head.next=head.next->next;
    }
    fclose(fp);
    fp=NULL;
    return ;
}    

void DestroyLinklist()
{
	List *p = Head.next;	
	while(p!=NULL)
	{
		Head.next = p->next;
		free(p);
		p = Head.next;
	}
	return;
} 
*/

int all(struct message *meag,clientinf *clientNode)
{
    LNODE *p=LHead.next;
    while(p!=NULL)
    {
        if(strcmp(p->data.name,(*meag).name)==0)
        {
            if(p->data.speak==0)
            {
                strcpy((*meag).flag,"sermsg");
                sprintf((*meag).msg,"sorry,you speak limited by manager!\n");
                write(p->data.decr,meag,sizeof(struct message));
                return 0;
            }



            else if(strcmp((*meag).msg,"")!=0)
            {
                LNODE *L=LHead.next;
                strcpy((*meag).name,(*clientNode).name);
                while(L!=NULL)
                {
                    write(L->data.decr,meag,sizeof(struct message));
                    L=L->next;
                }
                return 1;
            }
        }
        p=p->next;
    }
}  

int personal(struct message *meag,clientinf *clientNode)
{    
     LNODE *p=LHead.next;
     while(p!=NULL)
     {
         if(strcmp(p->data.name,(*meag).name)==0)
         {
             if(p->data.speak==0)
             {
                 strcpy((*meag).flag,"sermsg");
                 sprintf((*meag).msg,"sorry,you speak limited by manager!\n");
                 write(p->data.decr,meag,sizeof(struct message));
                 return 0;
             }
         }
         p=p->next;
     }



     clientinf data;
     strcpy(data.name,(*meag).addressee);
     LNODE *L=LHead.next;
     strcpy((*meag).name,(*clientNode).name);
     while(L!=NULL)
     {
         if(strcmp(data.name,L->data.name)==0)
         {
             if(strcmp((*meag).msg,"")!=0)
             {
                 write(L->data.decr,meag,sizeof(struct message));
                 return 1;
             }
         }
         L=L->next;
         
     }
     strcpy((*meag).flag,"sermsg");
     sprintf((*meag).msg,"the user not online\n");
     write((*clientNode).decr,meag,sizeof(struct message));
     return 0;
}  


int view(struct message *meag,clientinf *clientNode)
{
    char str[MAXLINE],buf[MAXLINE];
    int i=1;
    LNODE *L=LHead.next;
    bzero(buf,strlen(buf));
    while(L!=NULL)
    {   
        bzero(str,strlen(str));
        if(L->data.speak==1)
        {
            sprintf(str,"%d. %s  online\n",i,L->data.name);
            strcat(buf,str);
        }
        else
        {
              sprintf(str,"%d. %s  speak limited\n",i,L->data.name);
              strcat(buf,str);
        }   
        L=L->next;
        i++;
    }
    strcpy((*meag).name,(*clientNode).name);
    strcpy((*meag).msg,buf);
    write((*clientNode).decr,meag,sizeof(struct message));
}


int admin_kick(struct message *meag,clientinf *clientNode)
{   
    int closefd;
    LNODE *L=&LHead;
    while(L->next!=NULL)
    {
        if(strcmp(L->next->data.name,(*meag).msg)==0)
        {
            closefd=L->data.decr;
            close(closefd);
            LNODE *q=L->next;
            L->next=L->next->next;
            free(q);
            q=NULL;  
            strcpy((*meag).flag,"sermsg");
            sprintf((*meag).msg,"%s kicked out the chatroom by manager!",(*meag).msg);
            LNODE *p=LHead.next;
            while(p!=NULL)
            {
                write(p->data.decr,meag,sizeof(struct message));
                p=p->next;
            }
            return closefd;
        }
        L=L->next;
    }
    strcpy((*meag).flag,"sermsg");
    sprintf((*meag).msg,"the personal not online\n");
    write((*clientNode).decr,meag,sizeof(struct message));
    return 0;
}
 
int admin_screen(struct message  *meag,clientinf *clientNode)
{
    LNODE *L=LHead.next;
    while(L!=NULL)
    {
        if(strcmp(L->data.name,(*meag).msg)==0)
        {
            L->data.speak=(L->data.speak+1)%2;
            strcpy((*meag).flag,"sermsg");
            if(L->data.speak==0)
            {
                sprintf((*meag).msg,"%s speak limited by manager!",(*meag).msg);
            }
            else
            {
                sprintf((*meag).msg,"%s free by manager!",(*meag).msg);
            }
            LNODE *p=LHead.next;
            while(p!=NULL)
            {
                write(p->data.decr,meag,sizeof(struct message));
                p=p->next;
            }
            return 1;
        }
        L=L->next;
    }
    strcpy((*meag).flag,"sermsg");
    sprintf((*meag).msg,"this user not online!\n");
    write((*clientNode).decr,meag,sizeof(struct message));
    return 0;
}
        
int uexit(struct message *meag,clientinf *clientNode)
{
    LNODE *L=&LHead;
    while(L->next!=NULL)
    {
        if(L->next->data.decr==(*clientNode).decr)
        {
            strcpy((*clientNode).name,L->next->data.name);
            LNODE *q=L->next;
            L->next=L->next->next;
            free(q);
            q=NULL;  
            break;
        }
        L=L->next;
    } 
    strcpy((*meag).flag,"sermsg");
    printf("%s leave the chatroom!\n",(*clientNode).name);
    sprintf((*meag).msg,"%s leave the chatroom\n",(*clientNode).name);
    LNODE *p=LHead.next; 
    while(p!=NULL)
    {
        write(p->data.decr,meag,sizeof(struct message));
        p=p->next;
    }
}

int main(int argc, char **argv)
{
    struct sockaddr_in cliaddr, servaddr;
    struct message meag;
    
    
    clientinf clientNode;
    fd_set rset;
    socklen_t clilen;
    time_t timep;
    
    char str[MAXLINE];
    int listenfd, connfd;
    int maxfd;
    int ret;
    int clientfd[64] = {0};
    int i = 0;
    
    strcpy(clientNode.name,"*****");
    clientNode.speak=1;
    fd=open("chat.txt",O_RDWR|O_CREAT|O_APPEND,0777);
    if(fd<0)
    {
        perror("open fail:");
        exit(-1);
    } 
 
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(clientfd,0xff,sizeof(clientfd));

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_aton("192.168.1.73", &(servaddr.sin_addr));
    servaddr.sin_port = htons(5678);

    bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

    listen(listenfd, 5);

    maxfd = listenfd;
    for ( ; ; ) 
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
	    	if(errno == EINTR)
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
	    	clilen = sizeof(cliaddr);
	    	connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &clilen);
	    	addFd(clientfd,64,connfd);
		}
		for(i = 0; i < 64;i++)
		{
	    	if(clientfd[i] > 0)
	    	{
	        	if(FD_ISSET(clientfd[i],&rset))
				{
		    		int len;
		   
		    		len = read(clientfd[i],&meag,sizeof(meag));
                    clientNode.decr=clientfd[i];
                    strcpy(clientNode.name,meag.name);                    
		    		if(len == 0)
                    {   
                        	uexit(&meag,&clientNode);
                        	fflush(stdout);
		        			close(clientfd[i]);
                        	FD_CLR(clientfd[i],&rset);
							clientfd[i] = -1;
							continue;
		    		}                     
	            	write(1,meag.flag,sizeof(meag.flag));
                    printf("\n");
                    
                  
		    		if(strcmp(meag.flag,"login")==0)
                    {   
                        printf("%s  %s\n",meag.name,meag.msg);

                        if(overlap(meag)==0)
                        {
                            login(&meag,&clientNode);
                        }
                        else
                        {
                            strcpy(meag.msg,"overlap");
                            write(clientNode.decr,&meag,sizeof(struct message));
                        }
                        continue;
                    }
                    else if(strcmp(meag.flag,"reg")==0)
                    {
                        reg(&meag,&clientNode);
                        continue;
                    }
                    else if(strcmp(meag.flag,"all")==0)
                    {
                        if(all(&meag,&clientNode)==1)
                        {
                            bzero(str,strlen(str));
                            time(&timep);
                            sprintf(str,"%s%s TO %s: %s\n",ctime(&timep),meag.name,meag.addressee,meag.msg);
                            printf("%s",str);
                            write(fd,str,strlen(str));
                        }
                            
                    }
                    else if(strcmp(meag.flag,"personal")==0)
                    {
                        if(personal(&meag,&clientNode)==1)
                        {
                            bzero(str,strlen(str));
                            time(&timep);
                            sprintf(str,"%s%s TO %s: %s\n",ctime(&timep),meag.name,meag.addressee,meag.msg);
                            printf("%s",str);
                        }   write(fd,str,strlen(str));
                         
                    }
                    else if(strcmp(meag.flag,"view")==0)
                    {
                        view(&meag,&clientNode);
                        continue;
                    }
                    else if(strcmp(meag.flag,"admin_kick")==0)
                    {
                        int closefd;
                        closefd=admin_kick(&meag,&clientNode);
                        FD_CLR(closefd,&rset);
                        int j;
                        for(j=0;j<64;j++)
                        {
                            if(closefd == clientfd[j])
                            {
                                clientfd[j]=-1;
                                break;
                            }
                        }
                        continue;               
                    }
                    else if(strcmp(meag.flag,"admin_screen")==0)
                    {
                        admin_screen(&meag,&clientNode);
                        continue;
                    }
               		               
	        }    
	    }
      }
    }
    close(listenfd);
    return 0;
}



         

    
        
