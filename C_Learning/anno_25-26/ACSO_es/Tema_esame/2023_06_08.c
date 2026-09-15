/*
Si relizzi un programma in C secondo la seguente specifica
    1. Il programma utilizza un vettore globale values di 5000 interi
    2. Il programma deve elaborare l'intero vettore massimizzando il parallelismo
    3. Il programma genera 5 provessi figli
    4. Ogni processo figlio elabora 1000 elementi del vettore ed in particolare
        a. Spampa l'indice del primo e delll'ultimo elemento che elabora
        b. Calcola il totale degli elementi
        c. Stampa il totale degli elememnti
    5. Quando tutti i figli sono terminati il programma stampa un messaggio di fine calcolo.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int value[50] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0,3,4,5,6,0,6,7,7,8,9,4,5,67,8,5,3,4,5,5,6,6,7,9,6,7,7,9,4,4,4,4,4,4,4,4,45,5,5,9,6,};

int main(){
    pid_t pid;
    int dim = (sizeof(value) / sizeof(value[0])) / 5;

    // child
    for (int i = 0; i < 5; i++ ){
        pid = fork();
        if (pid == 0){
            int sum = 0;
            int start = i * dim;
            int end = start + dim - 1;
            printf("indice primo elemento: %d\nindice ultimo elemento: %d\n", start, end);
            for (int j = start; j < end+1; j++){
                sum += value[j];
            }
            printf("somma totale: %d\n", sum);
            exit(0);
        }
    }

    //parent
    for (int i = 0; i < 5; i++ ){
        wait(NULL);
    }
    printf("programma terminato");
    exit(0);
}