#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define SIZE 32

int main(int argc,char** argv){
	int fd,len;
	char buf[SIZE];

	if ((fd=open(argv[1],O_RDWR))==-1){
		printf("Open fail.\n");
		return -1;
	}
	
	len=read(fd,buf,SIZE);
	printf("read len=%d\n",len);
	len=write(fd,buf,SIZE);
	printf("write len=%d\n",len);

	close(fd);
	return 0;
}
