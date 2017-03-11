#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
char buf[100]="msg....";//读写缓冲区,共享资源
void *readString(void *arg) ;//读者函数
void *writeString(void *arg);//写者函数
pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;

void *readString(void *arg) //读者函数
{
    pthread_mutex_lock(&lock);
    printf("%s\n",buf);
    pthread_mutex_unlock(&lock);
}
void *writeString(void *arg)//写者函数
{
    pthread_mutex_lock(&lock);
    fgets(buf,100,stdin);
    pthread_mutex_unlock(&lock);
}

int main()
{
    pthread_t pt[2];
    int ret;
    ret=pthread_create(&pt[0],NULL,writeString,NULL);
    if(ret!=0)
    {
        printf("error");
        return -1;
    }
    pthread_join(pt[0],NULL);
    ret=pthread_create(&pt[1],NULL,readString,NULL);
    if(ret!=0)
    {
        printf("error");
        return -1;
    }
    pthread_join(pt[1],NULL);
    return 0;
}







