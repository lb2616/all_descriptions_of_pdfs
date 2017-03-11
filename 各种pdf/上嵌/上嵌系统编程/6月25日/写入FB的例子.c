#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/mman.h>

int main()
{
    unsigned char *addr=NULL;
    int fd=open("/dev/fb0",O_RDWR);
    if(fd<0)
    {
        perror("open()");
        return -1;
    }
    
    addr = mmap(NULL,1366*768*4,PROT_READ | PROT_WRITE, MAP_SHARED,fd,0);
    if(addr == MAP_FAILED)
    {
        perror("mmap()");
        return -1;
    }
    int i=0;
    int j=0;
    for(i=0;i<768;i++)
    {
        for(j=0;j<1366;j++)
        {
            addr[(i*1366 + j)*4 + 0]= 0;
            addr[(i*1366 + j)*4 + 1]= 123;
            addr[(i*1366 + j)*4 + 2]= 123;
            addr[(i*1366 + j)*4 + 3]= 255;
        }
    }
    close(fd);
    munmap(addr,1366*768*4);
    return 0;
}






