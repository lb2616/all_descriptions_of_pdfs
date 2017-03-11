#include<stdio.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#define N 40

int main(int argc,char **argv)
{
    FILE *fp;
    int line=0;
    char buf[N];
    if((fp=fopen("log.txt","a"))==NULL)// a 不可读 a+
    {
        printf("open file failed %s",strerror(errno));
        exit(0);
    }
    while((fgets(buf,40,fp))!=NULL)// a 不可读 a+,若为a则这段代码没有用
    {
        if(strlen(buf)<N-1 || buf[N-2]=='\n')
        {
            line++;
        }
    }
    while(1)
    {
        time_t t;
        struct tm *tm;
        time(&t);
        tm=localtime(&t);
        sprintf(buf,"%d %d/%d/%d   %d:%d:%d\n",++line,tm->tm_year+1900,tm->tm_mon+1,tm->tm_mday,tm->tm_hour,tm->tm_min,tm->tm_sec);
        printf("%s\n",buf);
        fputs(buf,fp);
        fflush(fp); //清空缓冲区 
        sleep(1);
    }
    fclose(fp);
    return 0;
}



