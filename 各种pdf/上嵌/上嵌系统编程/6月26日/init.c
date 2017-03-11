#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>

void init_daemon(void)
{
    int pid;
    int i;
    if(pid=fork())
    {
        exit(0);
    }
    else if(pid<0)
    {
        exit(-1);
    }
    setsid();
    if(pid=fork())
    {
        exit(0);
    }
    else if(pid<0)
    {
        exit(1);
    }
    for(i=0;i<getdtablesize();++i)
        close(i);
    chdir("/tmp");
    umask(0);
    return ;
}











