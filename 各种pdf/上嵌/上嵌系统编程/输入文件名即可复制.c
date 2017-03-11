#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>

int main(int argc,char **argv)
{
    int fd1=-1;//要复制的文件描述符为只读
    int fd2=-1;//要复制的文件描述符为只写
    unsigned char tmp=0;
    if(argc!=3)
    {
        printf("命令行参数应该为: ./copy file1 file2\n");
        return -1;
    }
    fd1=open(argv[1],O_RDONLY);//只读的方式打开     
    if(fd1<0)
    {
        printf("open file %s failed\n",argv[1]);
        return -1;
    }
    fd2=open(argv[2],O_WRONLY);//只写的方式打开     
    if(fd2<0)
    {
        printf("open file %s failed\n",argv[2]);
        return -1;
    }
    while(1==read(fd1,&tmp,1))
    {
        write(fd2,&tmp,1);
    }
}






























