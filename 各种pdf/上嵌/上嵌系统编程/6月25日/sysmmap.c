#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<errno.h>

typedef struct
{
    int integer;
    char string[24]; 
}RECORD;

#define NRECORDS 100

int main()
{
    RECORD record, *mapped;
    int i,f;
    FILE *fp;
    
    fp=fopen("records.dat","w+");
    if(fp==NULL)
    {
        perror("open() fail 0:");
        return -1;
    }
    for(i=0;i<NRECORDS;i++)
    {
        record.integer = i;
        sprintf(record.string,"RECORD-%d",i);
        fwrite(&record,sizeof(record),1,fp);
    }
    fclose(fp);
    
    fp=fopen("records.dat","r+");
    if(NULL==fp)
    {
        perror("open() fail 1:");
        return -1;
    }
    fseek(fp,43*sizeof(record),SEEK_SET);
    fread(&record,sizeof(record),1,fp);
    record.integer=143;
    sprintf(record.string,"RECORD-%d",record.integer);
    fseek(fp,43*sizeof(record),SEEK_SET);
    fwrite(&record,sizeof(record),1,fp);
    fclose(fp);
  
    f = open("records.dat",O_RDWR);
    if(f<0)
    {
        perror("open() fail 2 :\n");
        return -1;
    }
    RECORD rec;
    lseek(f,43*sizeof(rec),SEEK_SET);
    if((read(f,&rec,sizeof(rec)))<0)
    {
        perror("error");
        return 0;
    }
    printf("integer--%d,string--%s\n",rec.integer,rec.string);
    mapped=(RECORD *)mmap(0,NRECORDS*sizeof(record),PROT_READ|PROT_WRITE,MAP_SHARED,f,0);
    mapped[43].integer=243;
    sprintf(mapped[43].string,"RECORD-%d",mapped[43].integer);
    lseek(f,43*sizeof(rec),SEEK_SET);
    if((read(f,&rec,sizeof(rec)))<0)
    {
         perror("error");
         return 0;
    }
    printf("integer--%d,string--%s\n",rec.integer,rec.string);
    msync((void *)mapped,NRECORDS*sizeof(record),MS_ASYNC);
    munmap((void *)mapped,NRECORDS*sizeof(record));
    lseek(f,43*sizeof(rec),SEEK_SET);
    if((read(f,&rec,sizeof(rec)))<0)
    {
        perror("error");
        return 0;
    }
    printf("integer--%d,string--%s\n",rec.integer,rec.string);
    close(f);
    return 0;
}
















