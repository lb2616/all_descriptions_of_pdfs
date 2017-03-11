#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>

char message[32]="Hello world !";
void *thread_function1(void *arg);
void *thread_function2(void *arg);
int main(int argc,char *argv[])
{
    int ret1,ret2;
    pthread_t a_thread1;
    pthread_t a_thread2;
    void *thread_result;
    ret1 = pthread_create(&a_thread1,NULL,thread_function1,(void *)message);
    ret2 = pthread_create(&a_thread2,NULL,thread_function2,(void *)message);
    if(ret1<0)
    {
        perror("fail to pthread1 create");
        return -1;
    }
    printf("waiting for thread1 to finish \n");
    //等待线程结束
    ret1 = pthread_join(a_thread1,&thread_result);
    if(ret1<0)
    {
        perror("fail to pthread_join");
        return -1;
    }
    printf("MESSAGE is now %s\n",message);
    if(ret2<0)
    {
        perror("fail to pthread2 create");
        return -1;
    }
    printf("waiting for thread2 to finish \n");
    //等待线程结束
    ret2 = pthread_join(a_thread2,&thread_result);
    if(ret2<0)
    {
        perror("fail to pthread_join");
        return -1;
    }
    printf("MESSAGE is now %s\n",message);
    return 0;
}

void *thread_function1(void *arg)
{
    printf("thread_function1 is running ,arg is %s\n",(char *)arg);
    strcpy(message,"marked by thread1");
    pthread_exit("Thank you for the cpu time");
}

void *thread_function2(void *arg)
{
    printf("thread_function2 is running ,arg is %s\n",(char *)arg);
    strcpy(message,"marked by thread2");
    pthread_exit("Thank you for the cpu time");
}






