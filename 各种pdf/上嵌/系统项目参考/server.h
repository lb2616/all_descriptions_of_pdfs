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
#include <net/if.h>
#include <sys/ioctl.h>

#define MAXLINE 1000


typedef struct message
{
    char flag[15];       
    char name[20];
    char msg[MAXLINE];
    char addressee[20];
    int size;
}MESSAGE;

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
    int  ID;            //编号
    char ip[20];   		//获取本机ip用于通讯
	char qestion[30];   //备注信息用于找回密码
	char regtime[20];  	//存放注册的时间
}USER;

    
typedef struct _LNODE
{
    clientinf data;
    struct _LNODE *next;
}LNODE;

LNODE LHead;

typedef struct _STNODE
{
	USER user;    
	struct _STNODE *next;
}STNODE;


typedef struct _List
{
    USER user;
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

//读文件到链表的子函数,传递的参数是文件名
STNODE * readfiletolist(char filename[30]);

//保存函数
void save(STNODE *head,char filename[30]);

//获取系统时间
void systemtime(USER user);

void Readlinklisttofile();

//销毁链表---砍头法
void DestroyLinklist(STNODE *head);

void CoverBookNode();

int reg(struct message *meag,clientinf *clientNode);

int reg_check(struct message *meag);

//尾插法添加注册的人员信息
STNODE * insert(STNODE *head,USER user);

int all(struct message *meag,clientinf *clientNode);

int personal(struct message *meag,clientinf *clientNode);

int view(struct message *meag,clientinf *clientNode);








int admin_kick(struct message *meag,clientinf *clientNode);
int admin_screen(struct message  *meag,clientinf *clientNode);
int uexit(struct message *meag,clientinf *clientNode);
