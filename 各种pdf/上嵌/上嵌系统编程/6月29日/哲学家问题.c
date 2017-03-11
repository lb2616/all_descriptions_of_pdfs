/*
哲学家状态:eat 和 think
资源:5枝筷子
i,(i+1)%5
函数:eat();检测一下左右筷子的状态take_chopsticks();
函数:think(); putdown_chopsticks();
函数:哲学家函数:包含eat();think();
*/

#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>
#define N 5
#define LEFT (i-1+N)%N //define left source
#define RIGHT (i+1)%N //define right source
#define THINKING 0
#define EATING 1

int state[N];//5 philosopher
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutexattr_t attr;
void think(int i);
void take_forks(int i);
void eat(int i);
void put_forKs(int i);
int test(int i);
void *philosopher(void *i);
void *philosopher(void *i)
{
	int *num=(int *)i;
	think(*num);
	take_forks(*num);
	eat(*num);
	put_forks(*num);
}

void take_forks(int i)
{
    pthread_mutex_lock(&mutex);
    test(i);
    pthread_mutex_unlock(&mutex);
    return ;
}

void put_forks(int i)
{
    state[i]=THINKING;
}

int test(int i)
{
    if(state[LEFT]!=EATING && state[RIGHT]!=EATING);
    {
    	state[i]=EATING;
    	return 1;
    }
    return 0;
}

void eat(int i)
{
	if(state[i]==EATING)
	{
		printf("philosopher %d is eating......\n",i);
		sleep(2);
	}
}

void think(int i)
{
	if(state[i]==THINKING)
	{
		printf("philosopher %d is thinking......\n",i);
		sleep(2);
	}
}

int main()
{
	int i=0;
	pthread_t id[N];int ret;
	printf("testing ....\n");
	while(1)
	{
		for(i=0;i<N;i++)
		{
			ret=pthread_create(&id[i],NULL,philosopher,(void *)&i);
			printf("ret = %d\n",ret);
			if(ret<0)
			{
				printf("create pthread error !\n");
				return 1;
			}
			pthread_join(id[i],NULL);
		}
	}
}












