#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void ouch(int sig)
{
    printf("OUCH! -| got signal %d\n",sig);
}

int main()
{
    struct sigaction act;
    struct sigaction *pact =(struct sigaction *) malloc (sizeof(struct sigaction));
    act.sa_handler= SIG_DFL;
    sigemptyset(&act.sa_mask);
    act.sa_flags=0;
   
    sigaction(SIGINT,&act,NULL);
    pact->sa_handler = ouch;
    sigemptyset(&pact->sa_mask);
    pact->sa_flags=0;
    sigaction(SIGQUIT,pact,0);
    while(1)
    {
        printf("Hello World !\n");
        sleep(1);
    }
    free(pact); 
    return 0;
}
