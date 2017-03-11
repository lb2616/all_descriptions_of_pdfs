#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>

int main(int argc,char **argv)
{
    int fd;
    if(argc!=2)
    {
        printf("please input filename & path\n");
        return -1;
    }
    fd=open(argv[1],O_RDWR|O_CREAT|O_EXCL,0644);
    if(fd<0)
    {
        printf("open fail %s!!!\n",strerror(errno));
        return -1;
    }
    printf("open sucess!!!\n");
    char buf[20]="we are studying c";
    ssize_t count;
    count=write(fd,buf,sizeof(buf));
    if(count==sizeof(buf))
    {
        printf("write sucess!!!\n");
    }
    off_t offsize;
    offsize=lseek(fd,0,SEEK_SET);
    if(offsize<0)
    {
        printf("lseek fail %s\n",strerror(errno));
        return -1;
    }
    count=read(fd,buf,19);
    if(count<0) 
    {
        printf("read fail %s\n",strerror(errno));
        return -1;
    }
    printf("read string %s\n",buf);
    if(close(fd)<0)
    {
        printf("close fail %s!!!\n",strerror(errno));
    }
    return 0;
}
/*
while(1)
{
    pos=0;
    len=read(fd,buf,sizeof(buf));
    if(len==0)
        break;
    else if(len<0)
    {
        perror("read()");
        return -1;
    }
    while(len>0)
    {
        ret=write(fd2,buf+pos,len);
        if(ret<0)
        {
            perror("write()");
            return -1;
        }
        pos=pos+ret;
        len=len-ret;
    }
}
*/
