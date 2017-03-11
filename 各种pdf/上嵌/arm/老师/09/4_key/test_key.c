#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define NUM 6

int main(int argc,char** argv){
	int fd,i;
	int key_status[NUM];

	if ((fd=open(argv[1],O_RDWR))==-1){
		printf("Open fail.\n");
		return -1;
	}
	
	while(1){
		read(fd,key_status,6*sizeof(int));
		for(i=0;i<NUM;i++)
			if (key_status[i]==0)
				printf("Key %d is pressed.\n",i+1);
		sleep(1);
	}


	close(fd);
	return 0;
}
