/*
下面的例子是创建多个线程判断是否为素数
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

int Isprime(int start,int n)
{
    int i,j,flag=0;
    for(i=start;i<=start+n;i++)
    {
        for(j=2;j<i/2;j++)
        {
            if(i%j==0)
            {
                flag=0;
                return 0;
                
            }
        }
        return 1;
    }
    
}

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
    int sum=0;
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
    pthread_join(ptid1,NULL);
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


/**/
#include<stdio.h>
#include<pthread.h>

typedef struct
{
    
};



int isprime(int num)
{
    int i;
    for(i=2;i<(int)(num/2);i++)
    {
         if(num%i==0)
            return 0;
    }
    return 1;
}

void *function1(void *data)
{
    data=(int *)data;
    //使用时加锁
    pthread_mutex_lock(&(pri.mutex));
    int i;
    for(i=pri.start;i<pri.start+data;i++)
    {
        if(isprime(i))
        {
            printf("%d is a prime\n",i);
        }
        else
            printf("%d is not a prime \n",i);
    }
    pthread_mutex_unlock(&(pri.mutex));
    return NULL;
}


int main()
{
    pthread_t pth1,pth2;
    int increase=100;
    int increase1=500;
    pri.mutex=PTHREAD_MUTEX_INITIALIZER;//初始化锁;
    pthread_mutex_lock(&(pri.mutex));
    pri.start=1000;
    pthread_mutex_unlock(&pri.mutex);
    int ret1,ret2;
    ret1=pthread_create(&pth1,NULL,function1;(void *)&increase);
    ret2=pthread_create(&pth2,NULL,function2;(void *)&increase1);
    
    //判定

   
    ret1=pthread_join(pth1;NULL);
    ret2=pthread_join(pth2;NULL);
    return 0;
}



