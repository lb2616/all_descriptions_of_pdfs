/*
设计程序stdIOExercise3.c:编程读写一个文件test.txt,每
隔1秒向文件中写入一行数据,类似这样:
1, 2014-4-30 15:16:422, 2014-4-30 15:16:43
该程序应该无限循环,直到按Ctrl-C中断程序。
再次启动程序写文件时可以追加到原文件之后,并且序号能够接续
上次的序号,比如:
1,2014-4-30 15:16:42
2,2014-4-30 15:16:43
3,2014-4-30 15:19:02
4,2014-4-30 15:19:03
5,2014-4-30 15:19:04
www.qianrushi.com.
*/


#include<stdlib.h>
#include<stdio.h>
#include<time.h>

struct shijian
{
    int ID;   //秒–取值区间为[0,59] 
    int year; //年份，其值从1900开始 
    int mon;  //月份（从一月开始，0代表一月） - 取值区间为[0,11] 
    int day;  // 一个月中的日期 - 取值区间为[1,31] 
    int hour; // 时 - 取值区间为[0,23] 
    int min;  // 分 - 取值区间为[0,59] 
    int sec;  // 秒–取值区间为[0,59] 
};

//读文件取出当前文件中最大的ID编号
int readfileID(char filename[25])
{
    struct shijian sj;
    int bianhaoID;
    int filepos=0;
    FILE *file=NULL;
    file=fopen(filename,"rt");
    if(file==NULL)
    {
        printf("打开文件%s出错！\n",filename);
        return 0;
    }
    fseek(file,0,SEEK_END);
    filepos=ftell(file);//报告文件距离文件开头的位移量，如果为0，则表示文件为空
    if(filepos==0)
    {
        return 1;
    }
    else
    {
        fseek(file,-sizeof(struct shijian),SEEK_END);//放在文件末尾之前的一个结构体处
        fread(&sj,sizeof(struct shijian),1,file);
        bianhaoID=sj.ID+1;
        printf("%d\n",bianhaoID);
        fclose(file);
        file=NULL;
        return bianhaoID;
    }
}
void writetimetofile( char filename[30] )
{
    while(1)
    {
        FILE *fp;
        fp=fopen(filename,"at");
        if(fp==NULL)
        {
            printf("打开%s文件错误!!\n",filename);
            exit(1);
        }
        else
        {
            time_t rawtime;
            struct tm * timeinfo;
            struct shijian rtm;
            time ( &rawtime );
            timeinfo = localtime ( &rawtime );
            rtm.ID=readfileID("test.txt");
            rtm.year=timeinfo->tm_year+1900;
            rtm.mon=timeinfo->tm_mon;
            rtm.day=timeinfo->tm_mday;
            rtm.hour=timeinfo->tm_hour;
            rtm.min=timeinfo->tm_min;
            rtm.sec=timeinfo->tm_sec;
            sleep(1);
            fwrite(&rtm,sizeof(struct shijian),1,fp);
            fclose(fp);
            fp=NULL;
        }
    }
}
void readfile(char filename[30])
{
    FILE *fp;
    struct shijian rtm;
    fp=fopen(filename,"rt");
    if(fp==NULL)
    {
         printf("打开%s文件错误!!\n",filename);
         exit(1);
    }
    else
        {
            
            fread(&rtm,sizeof(struct shijian),1,fp);
            while(!feof(fp))
            {
                 printf("%-3d %-6d %-3d %-3d %-3d %-3d %-3d \n",rtm.ID,rtm.year,rtm.mon,rtm.day,rtm.hour,rtm.min,rtm.sec);
                 fread(&rtm,sizeof(struct shijian),1,fp);
            }
            fclose(fp);
            fp=NULL;
        }

    
}
int main ()
{
     int i;
     printf("请输入i的值  1:表示获取当前系统时间写进文件中  2:表示读文件 \n");
     scanf("%d",&i);
     switch(i)
     {
      case 1:
          writetimetofile("test.txt");
          break;
      case 2:
          readfile("test.txt");
          break;
     }
     return 0;
}






