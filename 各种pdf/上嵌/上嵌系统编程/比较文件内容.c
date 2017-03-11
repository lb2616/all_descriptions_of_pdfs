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
    int temp1=-1,temp2=-1;
    unsigned char tmp1=0;
    unsigned char tmp2=0;
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
    fd2=open(argv[2],O_RDONLY);//只写的方式打开     
    if(fd2<0)
    {
        printf("open file %s failed\n",argv[2]);
        return -1;
    }
    while(1)
    {
        temp1=read(fd1,&tmp1,1);
        temp2=read(fd2,&tmp2,1);
        if(tmp1==tmp2)
        {
            if(temp1==0&&temp2==0)  //这一步不能写成read(fd1,&tmp1,1)==0&&read(fd2,&tmp2,1)==0会造成fd1读了一次而fd2没有读
            {
                printf("%s和%s的内容相同\n",argv[1],argv[2]);
                break;
            }
        }
        if(tmp1!=tmp2)
        {
            printf("%s和%s的内容不相同\n",argv[1],argv[2]);
            break; 
        }
    }
/*
while(read(fd1,&tmp1,1) == 1 && read(fd2,&tmp2,1) == 1)
{
	if(tmp1 != tmp2)
			
}

if(read(fd1,&tmp1,1) == 1 || read(fd2,&tmp2,1) == 1)
*/
    close(fd1);
    close(fd2);
    return 0;
}

