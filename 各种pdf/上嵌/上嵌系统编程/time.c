#include "time.h"
#include<stdlib.h>
#include<stdio.h>
void main ()
{
time_t rawtime;
struct tm * timeinfo;
time ( &rawtime );
timeinfo = localtime ( &rawtime );
printf ( "\007The current date/time is: %s",asctime ( timeinfo ) );
exit(0);
}


/*
struct tm {
int tm_sec; /* 秒–取值区间为[0,59] 
int tm_min; /* 分 - 取值区间为[0,59] 
int tm_hour; /* 时 - 取值区间为[0,23]
int tm_mday; /* 一个月中的日期 - 取值区间为[1,31] 
int tm_mon; /* 月份（从一月开始，0代表一月） - 取值区间为[0,11] 
int tm_year; /* 年份，其值从1900开始 
int tm_wday; /* 星期–取值区间为[0,6]，其中0代表星期天，1代表星期一，以此类推 
*/
