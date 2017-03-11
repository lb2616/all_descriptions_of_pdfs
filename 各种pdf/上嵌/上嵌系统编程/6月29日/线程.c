#include<stdio.h>
#include<pthread.h>

int main()
{
    pthread_t tid;
    tid=pthread_self();
    printf("tid=%lu\n",(unsigned long)tid);
    return 0;
}
