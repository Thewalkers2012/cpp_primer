#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int a = 0;

void  handleSig5(int sig)
{
    a = 5;
    printf("before kill a = %d\n", a);
    kill(getpid(), 6);
    printf("after kill a = %d\n", a);
}


void  handleSig6(int sig)
{
    printf("set a to 6\n");
    a = 6;
}


int main(void) 
{
    struct sigaction act;
    act.sa_handler = handleSig5;
    sigaction(5, &act, NULL);
    act.sa_handler = handleSig6;
    sigaction(6, &act, NULL);
    printf("[%d]wait a signal....\n", getpid());
    getchar();

    return 0;
}