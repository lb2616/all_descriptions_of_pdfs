/*
下面的例子是创建两个线程对sum从1到100就行求和运算
*/

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

typedef struct ct_sum
{
    int sum;
    //int start;
    //int end;
    pthread_mutex_t lock;
}ct_sum;

void *add1(void *cnt)
{
    cnt=(ct_sum*)cnt;
    pthread_mutex_lock(&(((ct_sum*)cnt)->lock));
    int i;
    for(i=0;i<50;i++)
    {
        (*(ct_sum*)cnt).sum+=i;
    }
    pthread_mutex_unlock(&(((ct_sum*)cnt)->lock));
    pthread_exit(NULL);
    return 0;
}

void *add2(void *cnt)
{
    cnt=(ct_sum*)cnt;
    pthread_mutex_lock(&(((ct_sum*)cnt)->lock));
    int i;
    for(i=50;i<101;i++)
    {
        (*(ct_sum*)cnt).sum+=i;
    }
    pthread_mutex_unlock(&(((ct_sum*)cnt)->lock));
    pthread_exit(NULL);
    return 0;
}

int main()
{
    int i;
    pthread_t ptid1,ptid2;
   // int sum=0;
    ct_sum cnt;
    //ct_sum cnt1,cnt2;
    //cnt1.start=1;
    //cnt1.end=49;
    pthread_mutex_init(&(cnt.lock),NULL);
    //cnt.lock=THREAD_MUTEX_INITIALIZER;
    cnt.sum=0;
    pthread_create(&ptid1,NULL,add1,&cnt);
    pthread_create(&ptid2,NULL,add2,&cnt);
    pthread_mutex_lock(&(cnt.lock));
    printf("sum = %d\n",cnt.sum);
    pthread_mutex_unlock(&(cnt.lock));
    pthread_join(ptid1,NULL);//等待线程结束
/*
    pthread_mutex_lock(&(cnt.lock));
    printf("sum = %d\n",cnt.sum);
    pthread_mutex_unlock(&(cnt.lock));
*/
    pthread_join(ptid2,NULL); 
    pthread_mutex_destroy(&(cnt.lock));
    printf("sum = %d\n",cnt.sum);
    return 0;
}















