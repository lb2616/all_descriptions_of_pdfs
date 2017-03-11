#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#define SEQFILE "./seqno" //filename
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
#define MAXLINE 64
/*
S_IRUSR
  Permits the file's owner to read it.
S_IWUSR
  Permits the file's owner to write to it.
S_IRGRP
  Permits the file's group to read it.
S_IWGRP
  Permits the file's group to write to it.
|是位或运算符。
*/
void my_lock(int fd);
void my_unlock(int fd);

int main(int argc,char *argv[])
{
    int fd;
    long i,seqno=0;
    pid_t pid;
    ssize_t n;
    char line[MAXLINE + 1]={'\0'};
    pid = getpid();
    fd=open(SEQFILE,O_RDWR,FILE_MODE);
    if(fd<0)
    {
        printf("open %s failed\n",SEQFILE);
        return 1;
    }
    
    for(i=0;i<20;i++)
    {
        my_lock(fd);

        lseek(fd,0L,SEEK_SET);
        n=read(fd,line,MAXLINE);
        line[n]='\0';
        n=sscanf(line,"%ld\n",&seqno);
        printf("%s:pid = %ld,seq# = %ld\n",argv[0],(long)pid,seqno);
        seqno++;
        snprintf(line,sizeof(line),"%ld\n",seqno);
        lseek(fd,0L,SEEK_SET);
        write(fd,line,strlen(line));
  
        my_unlock(fd);
    }
    close(fd);
    return 0;

}











