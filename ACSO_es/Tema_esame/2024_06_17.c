/*
Si sviluppi in C un programma che prende in ingresso in testo e conta il numero di occorenze
di una data lettera. Per lo sviluppo del programma si considerino le seguenti assunzioni:
    - il testo e' memorizzato in un array globale **text[]**
    - La dimensione dell'array e' nota a compile time ed e' memorizzata nella variabile  **size**
    - La lettera da ricervare e' fornita sulla linea di comando
    = Al termine dell'elabirazione il programma deve stampare il conteggio richiesto
Il programma deve essere sviluppapo parallelizzando l'elaborazione su due thread. 
*/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

char text[] = "This is very long text...";
int size = sizeof(text);

char letter;

void* count(void* arg){
    int n = (int)arg;
    int dim = size / 2;
    int base = n * dim;
    int result = 0;
    for (int i = 0; i < dim; i++)
    {
        if(text[base+i]==letter){
            result++;
        }
    }
    return (void *)result;
}

int main(int argc, char*argv[]){

    if (argc != 2){
        exit(-1);
    }

    letter = argv[1][0];
    pthread_t tid1, tid2;

    pthread_create(&tid1, NULL, count, (void*)0);
    pthread_create(&tid2, NULL, count, (void*)1);

    int *res1, *res2;
    pthread_join(tid1, (void **)&res1);
    pthread_join(tid2, (void **)&res2);

    int sum = (int)res1 + (int)res2;

    printf("%d\n", sum);
}
