#include<stdio.h>
#include<sys/shm.h>
#include<sys/stat.h>

int main()
{
	int segment_id;
	char *shared_memory;
	key_t key = 0x1234;
	const int shm_size = 0x6400;
	segment_id = shmget(key,shared_segment_size,IPC_CREAT |IPC_EXCL | S_IRUSR | S_IWUSR);
	shared_memory = (char *)shmat(shmid,0,0);
	printf("shared memory at address %p\n",shared_memory);
	sprintf(shared_memory,"Hello,world.");
	shmdt(shared_memory);
	return 0;
}
