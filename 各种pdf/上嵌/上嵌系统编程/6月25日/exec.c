#include<stdio.h>
#include<unistd.h>

int main()
{
    char *const ls_argv[]={"ls","-al",NULL};
    execl("/bin/ls","ls","-al",NULL);
    execlp("ls","ls","-al",NULL);
    execvp("ls",ls_argv);
    return 0;
}
