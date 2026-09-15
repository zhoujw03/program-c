#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

typedef void (*sighandler_t)(int);

int go = 0;

void sigusr1_handeler(int sig){
    go++;
    printf("GOT: SIGURS1 - go = %d\n", go);

    // quando riceve segnale SIGUSR1 4 volte, viene cancellato la definizione personalizzato e ritorna alla funzione originale
    if (go == 4){
        signal(SIGUSR1, SIG_DFL);       
    }
}

int main(int argc, char ** argv){
    int n = 0;
    sighandler_t sigusr1_old;
    sighandler_t sigusr2_old;
   
    printf("MAIN: registering handelrs\n");
    sigusr1_old = signal(SIGUSR1, sigusr1_handeler);    // viene personalizzato il segnale SIGUSR1 con una nuova funzione      
    sigusr2_old = signal(SIGUSR2, SIG_IGN);             // ignora il segnale SIGUSR2

    printf("MAIN: waiting\n");

    while(go == 0)
        sleep(1); 

    while(1){
        printf("MAIN: %d\n", n++);
        sleep(1);
    }
    printf("MAIN: terminated correctly");

    exit(0);
}