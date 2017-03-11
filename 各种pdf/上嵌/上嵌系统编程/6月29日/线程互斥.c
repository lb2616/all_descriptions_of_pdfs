#include<stdio.h>
#include<pthread.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int n = 200000000;

void *func(void *data)
{
    int i=2;
    int flag=0;
    int num=0;
    while(1)
    {
        flag=0;
        pthread_mutex_lock(&lock);
        num=n;
        if(n==200000401)
        {
            pthread_mutex_unlock(&lock);
            break;
        }
        n=n+1;
        pthread_mutex_unlock(&lock);
        for(i=2;i<num;i++)
        {
            if(num%i==0)
            {
                 flag=1;
                 break;
            }
        }
        if(flag==1)
        {
            printf("%d is not prime\n",num);
        }
        else
        {
             printf("%d is prime \n",num);
        }
    }
    return NULL;
}


int main()
{
    int ret;
    int i;
    pthread_t tid[5];
    void *retval;
    for(i=0;i<5;i++)
    {
        ret = pthread_create(&tid[i],NULL,func,NULL);
        if(ret !=0)
        {
             printf("pthread_create error\n");
             return -1;
        }
    }
    for(i=0;i<5;i++)
    {
         pthread_join(tid[i],&retval);
    }
    return 0;
}







