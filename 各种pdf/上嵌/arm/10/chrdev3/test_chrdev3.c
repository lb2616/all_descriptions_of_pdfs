#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char** argv)
{
	int num=9;
	int fd,len;
	
	if((fd=open(argv[1],O_RDWR))==-1)
	{
		printf("open fail!\n");
		return -1;
	}
	while(1)
	{
		num=0;
		write(fd,&num,sizeof(int));
		sleep(1);
		num =1;
		write(fd,&num,sizeof(int));
		sleep(1);
	}
//	len=write(fd,&num,sizeof(int));
//	len=read(fd,&num,sizeof(int));
//	printf("read len=%d,num=%d\n",len,num);
	close(fd);
	return 0;

}
