#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#define NUM 6
int main(int argc,char** argv)
{
	int num=9;
	int key_status[NUM];
	int fd,len,i;
	
	if((fd=open(argv[1],O_RDWR))==-1)
	{
		printf("open fail!\n");
		return -1;
	}
	while(1)
	{
		read(fd,key_status,6*sizeof(int));
		for(i=0;i<NUM;i++)
		{
			if(key_status[i]==0)
			{
				printf("key %d is pressed.\n",i+1);
			}
		}
		sleep(1);
	}
//	len=write(fd,&num,sizeof(int));
//	len=read(fd,&num,sizeof(int));
//	printf("read len=%d,num=%d\n",len,num);
	close(fd);
	return 0;

}
