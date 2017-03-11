/*
做一个复制任意文本文件的程序
./copy_file a.txt b.txt
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
    FILE *fp1,*fp2;
    char ch1,ch2;
    fp1=fopen(argv[1],"r+");//不能用双引号引起来，因为“”会生成argv[1]
    fp2=fopen(argv[2],"w+");//argv[2]这两个文件，而不是后面运行是带的a.txt b.txt了
    if(fp1==NULL)
    {
        printf("cannot open the file\n");
   
        exit(0);  //终止函数
    }
    if(fp2==NULL)
    {
        printf("cannot open the file\n");
    
        exit(0);  //终止函数
    }
    while(1)
    {   
        ch1=fgetc(fp1); // 123 EOF
	if(feof(fp1))
        {   printf("文件复制成功！\n");
            break;
        }
        fputc(ch1,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    
    return 0;    
}
