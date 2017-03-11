/*
设计一个程序，建立文件employee.dat,结构体为包含部门号，员工号、姓名和工资，输入10个员工的记录，部门号分别为1，2，3，根据部门号排序，要求设计三个进程，第一个进程仅有对部门1的读权限，进程2对部门2有读写权限，进程3对部门3有读权限，设计这个程序，分别显示部门1和2的信息，更改部门2的所有的员工号。要求部门2的员工映射到内存进行读写。
*/

#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<errno.h>

typedef struct employee
{
    int department;
    int ID;
    char name[20];
    int salary;
}EMP;
int len=sizeof(EMP);
int main(int argc,char **argv)
{
    int fd,i=5,fd1;
    EMP emp1,emp2;
    char buf[len];
  /*  if(argc!=2)
    {
        printf("please input filename & path\n");
        return -1;
    }*/
    fd=open("employee.txt",O_RDWR|O_EXCL,0644);
    if(fd<0)
    {
        printf("open fail %s!!!\n",strerror(errno));
        return -1;
    }
 /*    printf("请输入部门职工的的信息:\n");
   while(i>0)
    {
        printf("职工所在部门:");
        scanf("%d",&emp1.department);
        printf("职工编号:");
        scanf("%d",&emp1.ID);
        printf("职工姓名:");
        scanf("%s",emp1.name);
        printf("职工工资:");
        scanf("%d",&emp1.salary);
        sprintf(buf,"%d%d%s%d\n",emp1.department,emp1.ID,emp1.name,emp1.salary);
        write(fd,buf,len);
        i--;
    }*/
    close(fd);
    fd1=open("employee.txt",O_RDWR|O_CREAT|O_EXCL,0644);
    printf("部门  编号  姓名  工资 \n"); 
    int count=read(fd1,&emp2,len);printf("count = %d\n",count);
    while(count>0)
    {sleep(3);
        printf("%-3d  %-3d  %-3s  %-3d \n",emp2.department,emp2.ID,emp2.name,emp2.salary);
        count=read(fd1,&emp2,len);
    }
    close(fd1);
 /*    FILE *fp;
    fp=fopen("employee.txt","r");
    fread(&emp2,len,1,fp);
    printf("部门  编号  姓名  工资 \n");
    while(!feof(fp))
    {//读取数据并打印
	printf("%-3d %-3d  %-3s %-3d\n",
                emp2.department,emp2.ID,emp2.name,emp2.salary);      
        fread(&emp2,len,1,fp);
    }    */    
}






















