#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>

char message[32]="Hello world !";
void *thread_function(void *arg);

int main(int argc,char *argv[])
{
    int ret;
    pthread_t a_thread;
    void *thread_result;
    ret = pthread_create(&a_thread,NULL,thread_function,(void *)message);
    if(ret<0)
    {
        perror("fail to pthread create");
        return -1;
    }
    printf("waiting for thread to finish \n");
    //等待线程结束
    ret = pthread_join(a_thread,&thread_result);
    if(ret<0)
    {
        perror("fail to pthread_join");
        return -1;
    }
    printf("MESSAGE is now %s\n",message);
    return 0;
}

void *thread_function(void *arg)
{
    printf("thread_function is running ,arg is %s\n",(char *)arg);
    strcpy(message,"marked by thread");
    pthread_exit("Thank you for the cpu time");
}








