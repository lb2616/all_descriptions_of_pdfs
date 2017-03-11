#include<stdlib.h>
#include<stdio.h>

int main(int argc,char *argv[])
{
    printf("system() start....\n");
    system("ls -l");
    printf("system() end....\n");
    return 0;
}
