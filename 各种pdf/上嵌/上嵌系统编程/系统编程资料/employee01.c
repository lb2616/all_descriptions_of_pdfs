 #include<stdio.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include<errno.h>
 #include<unistd.h>
 #include<string.h>

#define FILE_NAME "employee.dat"


typedef struct EMPLOYEES
{
	int iDepartmentNum; //部门号
	int iEmployeeNum;  //员工号
	char szName[64];  //姓名
	double dWage;    //工资
}EMPLOYEE;


EMPLOYEE InputEmployee(int i)
{
	EMPLOYEE buf;
	printf("请输入部门号（1 2 3）：");
	scanf("%d",&buf.iDepartmentNum);
	
	buf.iEmployeeNum = 1000+10-i;
	
	printf("请输入姓名：");
	scanf("%s",buf.szName);
	
	printf("请输入工资：");
	scanf("%lf",&buf.dWage);
	
	return buf;
}

int Writefile(int i)
{
	int fd;
	EMPLOYEE buf;
	fd = open(FILE_NAME,O_RDWR);
	if(fd<0)
    {
         printf("open file %s\n",strerror(errno));
         return -1;
    }
    printf("open sucess\n");
    buf = InputEmployee(i);
    ssize_t len,ret;
	len = sizeof(buf);
	lseek(fd,0L,SEEK_END);
    while(len > 0)
    {
         ret = write(fd,&buf,len);
         if(ret < 0)
         {
		     perror("write()");
 		     return -1;
 	     }
         len = len - ret;    
    }
    Show(buf);
    close(fd);
    return 0;
}

int Show(EMPLOYEE buf)
{
	printf("%2d %5d %8s %0.2lf\n",
			buf.iDepartmentNum,
			buf.iEmployeeNum,
			buf.szName,
			buf.dWage );
	return;
}

int Readfile()
{
	int fd;
	EMPLOYEE buf;
	fd = open(FILE_NAME,O_RDONLY);
	if(fd<0)
    {
         printf("open file %s\n",strerror(errno));
         return -1;
    }
    printf("open sucess\n");
    ssize_t len;
	len = sizeof(buf);
    while(1)
    {   
 	    len = read(fd,&buf,sizeof(buf));
 	    if(0 == len)
 	        break;
 	    else if(len < 0)
 	    {
 	        perror("read()");
 	        return -1;
 	    } 	
 	     Show(buf);    
    }
    close(fd);
    return 0;
}

int main(int argc,char *argv[])
{
/*	int i = 2;
	while(i)
	{
		Writefile(i);
		i--;
		printf("i = %d\n",i);	
	}
*/
	printf("部门号 员工号 姓名 工资\n");
	Readfile();
	return 0;
}


