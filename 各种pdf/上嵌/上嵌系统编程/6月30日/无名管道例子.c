#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

struct stu
{
    int id;
    char name[32];
    int age;
    char addr[64]; 
};

int main()
{
    int ret;
    int stutas;
    char buf[32]={0};
    pid_t pid;
    struct stu s;
    int fd[2];
    ret = pipe(fd);
    if(ret<0)
    {
    	perror("pipe()");
    	return -1;
    }
    pid = fork();
    if(pid== 0)
    {
    	s.id = 1;
    	strcpy(s.name,"张三");
    	s.age = 22;
    	strcpy(s.addr,"上海市");
    	write(fd[1],&s,sizeof(s));
    }
    else if(pid>0)
    {
    	printf("start:stu:id = %d,name  = %s,age = %d,addr =%s \n",s.id,s.name,s.age,s.addr);
    	ret = read(fd[0],&s,sizeof(s));
    	printf("start:stu:id = %d,name  = %s,age = %d,addr =%s \n",s.id,s.name,s.age,s.addr);
    	wait(&stutas);
    }
    else
    {
    	perror("fork()");
    	return -1;
    }
    close(fd[0]);
    close(fd[1]);
    return 0;
}





