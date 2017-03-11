#include<stdio.h>
#include<sys/shm.h>
#include<sys/stat.h>

int main()
{
	int shmid;
	char *shared_memory;
	key_t key = 0x1234;
	const int shm_size = 0x6400;
	shmid = shmget(key,shm_size,IPC_CREAT | S_IRUSR | S_IWUSR);
	shared_memory = (char *)shmat(shmid,0,0);
	printf("shared memory at address %p\n",shared_memory);
	printf("%s\n",shared_memory);
	shmdt(shared_memory);
	shmctl(shmid,IPC_RMID,0);
	return 0;
}
