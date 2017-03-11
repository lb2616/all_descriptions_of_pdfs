#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>
#include<semaphore.h>
char buf[60];
void *function(void *arg);
sem_t sem;

void *function(void *arg)
{
    while(1)
    {
        sem_wait(&sem);
        printf("You enter %lu characters\n",strlen(buf)-1);
    }
}

int main(int argc,char *argv[])
{
    int ret;
    pthread_t tid;
    if(pthread_create(&tid,NULL,function,NULL)<0)
    {
        perror("fail to pthread_create\n");
        exit(-1);
    }
    ret = sem_init(&sem,0,0);
    if(ret<0)
    {
        perror("fail to sem_init\n");
        exit(-1);
    }
    do
    {
        printf(">");
        fflush(stdout);
        fgets(buf,60,stdin);
        sem_post(&sem);
    }while(strncmp(buf,"quit",4)!=0);
    return 0;
}





