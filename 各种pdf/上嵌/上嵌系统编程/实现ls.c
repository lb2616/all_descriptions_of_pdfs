#include <sys/types.h>
#include <sys/stat.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<pwd.h>
#include<time.h>
#include<grp.h>

int main(int argc,char **argv)
{
    struct stat buf;
    char out[100];
    if(argc==1)
    {
        fprintf(stderr,"Using %s filename\n",argv[0]);
        return 0;
    }
    if(lstat(argv[1],&buf)<0) //获取文件信息失败
    {
        fprintf(stderr,"stat error:%s\n",strerror(errno));
        return -1; 
    }
    /*
    printf("-----%o\n",buf.st_mode);//如果是普通文件
    if(S_ISREG(buf.st_mode))
        printf("-");
    else if(S_ISDIR(buf.st_mode))
        printf("d");
    else if(S_ISCHR(buf.st_mode))
        printf("c");
    else if(S_ISFIFO(buf.st_mode))
        printf("p");
    else if(S_ISLNK(buf.st_mode))
        printf("l");
    else if(S_ISSOCK(buf.st_mode))
        printf("s");
    */
    switch(buf.st_mode & S_IFMT)
    {
        case S_IFREG:
             printf("-");
             break;
        case S_IFDIR:
             printf("d");
             break;
        case S_IFCHR:
             printf("c");
             break;
        case S_IFBLK:
             printf("b");
             break;
        case S_IFIFO:
             printf("p");
             break;
        case S_IFLNK:
             printf("l");
             break;
        case S_IFSOCK:
             printf("s");
             break;
    }
    /*
    if(S_IRUSR & buf.st_mode)
        printf("r");
    else 
        printf("-");
    if(S_IWUSR & buf.st_mode)
        printf("w");
    else
        printf("-")
    if(S_IXUSR & buf.st_mode)
        printf("x"); 
    else 
        printf("-");
    if(S_IRGRP & buf.st_mode)
        printf("r");
    else
        printf("-");
    if(S_IWGRP & buf.st_mode)
       printf("w");
    else 
       printf("-");
    if(S_IXGRP & buf.st_mode)
       printf("x");
    else 
       printf("-");
    if(S_IROTH & buf.st_mode)
       printf("r");
    else   
       printf("-");
    if(S_IWOTH & buf.st_mode)
       printf("w");
    else   
       printf("-");
    if(S_IXOTH & buf.st_mode)
       printf("x");
    else   
       printf("-");
    */
    
    int n;
    for(n=8;n>=0;n--)
    {
        if(buf.st_mode&(1<<n))
        {
             switch(n%3)
             {
                 case 2:
                     printf("r");
                     break;
                 case 1:
                     printf("w");
                     break;
                 case 0:
                     printf("x");
                     break;
                 default:
                     break;
             }
        }
        else
        {
            printf("-");
        }
    }
    printf("%3d ",buf.st_nlink);

    struct passwd *pw;
    pw=getpwuid(buf.st_uid);
    printf("%s ",pw->pw_name);

    struct group *gr;
    gr=getgrgid(buf.st_gid);
    printf("%s ",gr->gr_name);
    printf("%3ld",buf.st_size);

    struct tm *t;
    t=localtime(&buf.st_atime);
    printf("%5d-%2d-%d %2d:%3d ",t->tm_year+1900,t->tm_mon+1,t->tm_mday,t->tm_hour,t->tm_min);
    printf("%s ",argv[1]);
    
    if(S_ISLNK(buf.st_mode))
    {
        printf("->");
        if(readlink(argv[1],out,100)==-1)
        {
              
        }
        printf("%s ",out);
    }
    printf("\n");
    return 0;
}























