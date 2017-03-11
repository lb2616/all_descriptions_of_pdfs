#include <sys/types.h>
#include <sys/stat.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>

int main(int argc,char **argv)
{
    if(argc!=2)
    {
        printf("please input dir name\n"); 
        return ;
    }
    int ret=mkdir(argv[1],0777);
    if(ret<0)
    {
        printf("create dir fail %s!!\n",strerror(errno));
        return 0;
    }
    printf("create success!!\n");
    ret=chdir(argv[1]);
    if(ret<0)
    {
        printf("change fail %s\n",strerror(errno));
        return 0;
    }
    printf("change success!!\n");
    return 1;
}
