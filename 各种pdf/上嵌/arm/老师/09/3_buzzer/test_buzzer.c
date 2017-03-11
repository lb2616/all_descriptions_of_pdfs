#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc,char** argv){
	int fd,len;
	int num=0;

	if ((fd=open(argv[1],O_RDWR))==-1){
		printf("Open fail.\n");
		return -1;
	}
	
	while(1){
		num=0;
		write(fd,&num,sizeof(int));
		sleep(1);

		num=1;
		write(fd,&num,sizeof(int));
		sleep(1);
	}

	close(fd);
	return 0;
}
