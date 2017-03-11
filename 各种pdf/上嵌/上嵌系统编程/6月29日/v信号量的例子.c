#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<stdio.h>

int main()
{
    int semid;
    int semval;
    key_t key = 1234;
    semid = semget(key,1,IPC_CREAT | 0644);
    semctl(semid,0,SETVAL,10);
    semval=semctl(semid,0,GETVAL);
    printf("1 : semval = %d\n",semval);
    struct sembuf buf;
    buf.sem_num=0;
    buf.sem_op=-2;
    buf.sem_flg=0;
    semop(semid,&buf,1);
    semval=semctl(semid,0,GETVAL);
    printf(" 2 : semval = %d\n",semval);
    semctl(semid,0,IPC_RMID);   
    return 0;
}
