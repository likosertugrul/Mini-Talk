#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int sig)
{
    if (sig == SIGUSR1)
    {
        printf("SIGUSR1 sinyali alındı \n");
    }
    else if (sig == SIGUSR2)
    {
        printf("SIGUSR2 sinyali alındı \n");
    }
    
}

int main(int argc, char const *argv[])
{
    pid_t server_pid;
    struct sigaction sa;
    server_pid = getpid();
    printf("Server çalışıyor PID: %d \n", server_pid);

    sa.sa_handler = handle_signal;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1)
    {
        pause();
    }
    
    return 0;
}
