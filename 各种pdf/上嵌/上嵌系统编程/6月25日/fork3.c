#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    int n=1;
    pid_t pid;
    pid = fork();
    if(pid>0)
    {
        sleep(3);
        printf("n = %d \n",n);
    }
    else if(pid == 0)
    {
        n = 3;printf("n = %d \n",n);
    }
    else
    {
        perror("fork()");
    }
    return 0;
}


