#include<stdio.h>
#include<sys/shm.h>
#include<sys/stat.h>

int main()
{
	int segment_id;
	char *shared_memory;
	struct shmid_ds shmbuffer;
	key_t key = 0x1234;
	
	const int shared_size = 0x6400;
	segment_id = shmget(key,shared_size,IPC_CREAT|IPC_EXCL|S_IRUSR|S_IWUSR);
	shared_memory = (char *)shmat(segment_id,0,0);
	printf("shared memory attached at address %p\n",shared_memory);
	shmctl(segment_id,IPC_STAT,&shmbuffer);
	printf("segment size :%ld\n",shmbuffer.shm_segsz);
	sprintf(shared_memory,"Hello,World.");
	shmdt(shared_memory);
	shared_memory=(char *)shmat(segment_id,0,0);
	printf("shared memory at address %p\n",shared_memory);
	printf("%s\n",shared_memory);
	shmdt(shared_memory);
	shmctl(segment_id,IPC_RMID,0);
	return 0;
}





