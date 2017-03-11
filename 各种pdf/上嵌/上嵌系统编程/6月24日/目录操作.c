#include<stdio.h>
#include<dirent.h>

int main()
{
    struct dirent *d;
    DIR *dir = opendir(".");//读取当前文件夹
    if(dir==NULL)
    {
        perror("opendir()");
        return -1;
    }
    //readdir 每一次都返回文件夹中的一项,知道返回NULL
    while((d = readdir(dir))! = NULL)
    {
        printf("%s \n",d->d_name);
    }
    closedir(dir);
    return 0;
}
