#include<unistd.h>
#include<fcntl.h>

//void my_lock(int fd,struct flock lock)
void my_lock(int fd)//l.对加锁文件的步骤:int fd =open()打开文件
{
    struct flock lock;
    lock.l_type=F_WRLCK;
    lock.l_whence=SEEK_SET;
    lock.l_start=0;
    lock.l_len=0;
    fcntl(fd,F_SETLKW,&lock);//fcntl(fd,F_SETLK,&lock);
}
 
//void my_unlock(int fd,short whence,short start,short len)
void my_unlock(int fd)
{
    struct flock lock;
    lock.l_type=F_UNLCK;
    lock.l_whence=SEEK_SET;
    lock.l_start=0;
    lock.l_len=0;
    fcntl(fd,F_SETLK,&lock);
}

















