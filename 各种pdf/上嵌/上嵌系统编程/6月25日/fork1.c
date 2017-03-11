#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    int count=0;
    pid_t pid;
    pid=fork();
    if(pid>0)
    {
        printf("child pid = %d \n",pid);
        ++count;
        printf("count = %d \n",count);
        int pvar=10;//只能属于父进程,在块当中定义的,不复制
        printf("pvar = %d \n",pvar);
    }
    else if(pid==0)//单独执行的相互不影响
    {
        count+=3;
        printf("child count = %d \n",count);
    }
    else
    {
        printf("create fail \n");
        return -1;
    }
    printf("outer count = %d \n",count);
    return 0;
}
