#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>

void *my_handler(void *data)
{
    int *b=(int *)data;
    printf("hello new pthread ... b =%d\n",*b);
    int *a=(int *)malloc(sizeof(int));
    *a=321;
    return a;
}

int main()
{
    int ret ;
    pthread_t tid;
    void *p;
    int a=1000;
    ret = pthread_create(&tid,NULL,my_handler,(void *)&a);
    pthread_join(tid,&p);
    printf("a = %d\n",a);
    printf("return value = %d\n",*(int *)p);
    free(p);
    return 0;
}
