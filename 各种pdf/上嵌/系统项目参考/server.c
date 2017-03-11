#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <time.h>
#include <unistd.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <strings.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/time.h>

#include <sys/stat.h>
#include <fcntl.h>


#define MAXLINE 1000


struct message
{
    char flag[15];       
    char name[20];
    char msg[MAXLINE];
    char addressee[20];
    int size;
};

typedef struct _clientinf
{
    char name[20];
    struct sockaddr_in addr_in;
    int decr;
    pthread_t pid;
    int speak;
    
}clientinf;

typedef struct _User
{
    char name[20];
    char passwd[20];
}User;

    
typedef struct _LNODE
{
    clientinf data;
    struct _LNODE *next;
}LNODE;

LNODE LHead;


typedef struct _List
{
    User user;
    struct _List *next;
}List;

List Head;




int getMaxFd(int * pint,int size);
void addFd(int * pint,int size,int fd);
void setAllFd(int * pint,int size,fd_set * fdset);

int fd;
int overlap(struct message meag);
int login(struct message *meag,clientinf *clientNode);
int login_check(struct message *meag);
int insertend(clientinf *clientNode);
void Readfiletolinklist();
void Readlinklisttofile();
void DestroyLinklist();
void CoverBookNode();
int reg(struct message *meag,clientinf *clientNode);
int reg_check(struct message *meag);
int insert(User user);
int all(struct message *meag,clientinf *clientNode);
int personal(struct message *meag,clientinf *clientNode);
int view(struct message *meag,clientinf *clientNode);
int admin_kick(struct message *meag,clientinf *clientNode);
int admin_screen(struct message  *meag,clientinf *clientNode);
int uexit(struct message *meag,clientinf *clientNode);

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
                        uexit(&meag,&clientNode);//
                        fflush(stdout);//
		        close(clientfd[i]);
                        FD_CLR(clientfd[i],&rset);//
			clientfd[i] = -1;
			continue;
		    }
                                      
                                     
	            write(1,meag.flag,sizeof(meag.flag));
                    printf("\n");
                    
                  
		    if(strcmp(meag.flag,"login")==0)
                    {   
                        printf("%s  %s\n",meag.name,meag.msg);
                        printf("00000000\n");

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
    DestroyLinklist();
    Readfiletolinklist();
    CoverBookNode();
    List *p=Head.next;
    if( strcmp((*meag).name,"admin")==0)
    {
        while(p!=NULL)
        {    
       
            if(strcmp(p->user.name,"admin")==0)
             
                if(strcmp(p->user.passwd,(*meag).msg)==0)
                  
                    return 0;
        
            p=p->next;        
        }
    }
    List *L=Head.next;
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
    if(strcmp(meag->name,"admin")==0)
        return 0;
    if(strcmp(meag->name,"all")==0)
        return 0;
    if(strcmp(meag->name,"reg")==0)
        return 0;
    if(strcmp(meag->name,"login")==0)
        return 0;
    if(strcmp(meag->name,"trans")==0)
        return 0;
    Readfiletolinklist();
    List *p=Head.next;
    while(p!=NULL)
    {    
        if(strcmp(p->user.name,meag->name)==0)
        {
                return 0;
        } 
        p=p->next;        
    }
    User user;
    strcpy(user.name,meag->name);
    strcpy(user.passwd,meag->msg);
    insert(user);
    Readlinklisttofile();
    DestroyLinklist();
    return 1;
}  

int insert(User user)
{
    List *pnode=malloc(sizeof(LNODE));
    pnode->user=user;
    pnode->next=NULL;
   
    pnode->next=Head.next;
    Head.next=pnode;
    
    return;
} 
          
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
        {
            
            List *p=malloc(sizeof(struct _List));
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
         

    
        
