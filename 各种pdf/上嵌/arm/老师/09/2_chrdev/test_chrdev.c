#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc,char** argv){
	int fd,len;
	int num=9;

	if ((fd=open(argv[1],O_RDWR))==-1){
		printf("Open fail.\n");
		return -1;
	}
	
	len=write(fd,&num,sizeof(int));
	len=read(fd,&num,sizeof(int));
	printf("read len=%d,num=%d\n",len,num);

	close(fd);
	return 0;
}
