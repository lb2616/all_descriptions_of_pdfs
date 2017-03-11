#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int global=22;
char buf[]="the test content!\n";
 
int main()
{
    int test = 0,stat;
    pid_t pid;
    if(write(STDOUT_FILENO,buf,sizeof(buf))!=sizeof(buf))
    {
        perror("write error!");
    }
    printf("fork test!\n");
    pid = fork(); 
    if(pid == -1)
    {
        perror("fork");
        exit(0);
    }
    else if(pid == 0)
    {
         global++;test++;
         printf("global=%d test=%d child ,myPID id %d \n",global,test,getpid());
             exit(0);
    }
    global+=2;
    test+=2;
    printf("global=%d test=%d parent,myPID is %d\n",global,test,getpid());
    exit(0);
    }






