/*
父进程从管道读,把读出来的
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
int main(int argc,char **argv)
{
	pid_t pid;
	int fd[2];
	int status;
	int ffd;
	char buf[100];
	int ret;
	ret = pipe(fd);
	if(ret<0)
	{
		perror("pipe fail");
		exit(-1);
	}
	ffd=open("text.dat",O_WRONLY|O_CREAT|O_EXCL,0644);
	if(ffd<0)
	{
		perror("open fail :");
		exit(-1);
	}
	pid= fork();
	if(pid<0)
	{
		perror("fork fail :");
		exit(-1);
	}
	if(pid==0)
	{
		fgets(buf,sizeof(buf),stdin);
/*		while(strcmp(buf,"bye")!=0)//在管道中的是在内核中的,容量小,必须读一个写一个,否则就是堵塞状态
		{
			write(fd[1],buf,strlen(buf));
			fgets(buf,sizeof(buf),stdin);
		}*/
	}
	else
	{
		read(fd[0],buf,sizeof(buf));
		write(ffd,buf,strlen(buf));
		wait(&status);
		
	}
	close(fd[0]);
	close(fd[1]);
	close(ffd);
    return 0;	
}













