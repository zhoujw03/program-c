#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

typedef void (*sighandler_t)(int);

void sigusr1_handeler(int sig){
    printf("GOT: SIGURS1\n");
}

void sigusr2_handeler(int sig){
    printf("GOT: SIGURS2\n");
}

int main(int argc, char ** argv){
    int n = 0;
    sighandler_t sigusr1_old;
    sighandler_t sigusr2_old;

    printf("MAIN: registering handelrs\n");
    sigusr1_old = signal(SIGUSR1, sigusr1_handeler);
    sigusr2_old = signal(SIGUSR2, sigusr2_handeler);

    printf("MAIN: waiting forever\n");
    while(1){
        printf("MAIN: %d\n", n++);
        sleep(1);
    }

    exit(0);
}