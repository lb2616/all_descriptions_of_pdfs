#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#define ABPATH "/tmp/AtoB"

void *func(void *param)
{
	char buf[32] = {0};
	int fd;
	fd = open(ABPATH,O_RDONLY);
	if(fd<0)
	{
		perror("open()");
		exit(-1);
	}
	
	while(1)
	{
		read(fd,buf,sizeof(buf));
		printf("对方说:%s\n",buf);
	}
	close(fd);
}

int main()
{
	int fd;
	int ret;
	char buf[32];
	if(access(ABPATH,F_OK) == -1)
	{
		ret = mkfifo(ABPATH,0777);
		if(ret<0)
		{
			perror("mkfifo()");
		}
	}
	pthread_t tid;
	pthread_create(&tid,NULL,func,NULL);
	fd = open(ABPATH,O_WRONLY);
	if(fd<0)
	{
		perror("open()");
		return -1;
	}
	while(1)
	{
		printf(">");
		fflush(stdout);
		fgets(buf,sizeof(buf),stdin);
		write(fd,buf,sizeof(buf));
	}
	close(fd);
	return 0;
}





