#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void compare(char filename1[20],char filename2[20])
{
    FILE *fp1,*fp2;
    fp1=fopen(filename1,"r");
    fp2=fopen(filename2,"r");
    if(fp1==NULL)
    {
        printf("cannot open the file %s \n",filename1);
        exit(0);  //终止函数
    }
    if(fp2==NULL)
    {
        printf("cannot open the %s file\n",filename2);
        exit(0);  //终止函数
    }
    char ch1,ch2;
    ch1=fgetc(fp1); // 123 EOF
    ch2=fgetc(fp2);
    while(1)
    {   
        if(ch1==ch2)
        {
            if(feof(fp1)&&feof(fp2))//文件到达结尾是返回值为非零的数
            {  
                printf("文件内容相同!!!\n");
                break;
            }
        }
        if(ch1!=ch2)
        {  
            printf("文件内容不相同!!!\n");
            break;
        }
        ch1=fgetc(fp1); 
	ch2=fgetc(fp2);
    }
    fclose(fp1);
    fclose(fp2);
    return;   
}

int main(int argc,char *argv[])
{
    compare(argv[1],argv[2]);
    return 0;
}











