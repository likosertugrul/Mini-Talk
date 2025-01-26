#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t a;
    a = getpid();
    printf("%d \n", a);
    while (1)
    {
        pause();
    }
    
    return 0;
}
