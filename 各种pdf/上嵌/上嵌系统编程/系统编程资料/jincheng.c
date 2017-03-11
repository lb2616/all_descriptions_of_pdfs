#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
    printf("The process ID is %d\n",getpid());
    printf("The parent process ID is %d\n",getppid());
    return 0;
}
