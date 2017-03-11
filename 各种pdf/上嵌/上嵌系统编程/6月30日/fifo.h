#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<unistd.h>
typedef struct
{
	char address[40];
	short port;
	char msg[100];
}NETMSG;
#define FIFO "/tmp/fifo.txt"
