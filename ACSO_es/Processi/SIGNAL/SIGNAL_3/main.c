#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

void foo(int n){
    while(n--){
        printf("FOO: %d\n", n);
        sleep(1);
    }
}

int main(int argc, char **argv){
    int duration;

    if(argc != 2){
        printf("Usage: main <seconds>\n");
        exit(1);
    }

    duration = atoi(argv[1]);

    printf("MAIN: setting alarm\n");
    //viene impostato un tempo, se non termina entro il tempo impostato il programma manda un segnale SIGALRM al sistema
    alarm(5);

    foo(duration);

    //cancella allarme
    alarm(0);

    printf("MAIN: timeout met, continuing\n");

    exit(0);
}