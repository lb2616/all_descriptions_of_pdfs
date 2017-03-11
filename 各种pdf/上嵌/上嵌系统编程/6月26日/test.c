#include<stdio.h>
#include<time.h>

void init_daemon(void);

int main()
{
    FILE *fp;
    time_t t;
    init_daemon();

    while(1)
    {
        sleep(2);
        if((fp=fopen("test.log","a"))!=NULL)
        {
            t=time(0);
            fprintf(fp,"I'm here at %sn",asctime(localtime(&t)));
            fclose(fp);
        }
    }
    return 0;
}
