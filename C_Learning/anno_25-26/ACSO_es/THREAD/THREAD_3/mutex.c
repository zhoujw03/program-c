// uso del mutex per la sincronizzazione

#include<stdio.h>
#include <pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>

#define SIZE 20


int N[SIZE] = {3,1,4,5,6,5,5,7,5,3,5,6,3,5,3,9,0,2,5,8};

int c = 0;  //contatore globele

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

void *count(void * arg){

    // trasforma puntatore nel tipo long
    long start = (long)arg;
    int lc = 0;

    // scansiona meta dei elementi che compome l'array
    for (int i = start; i < start+SIZE/2; i++){
        if(N[i]==5)
            lc++;
    }
    pthread_mutex_lock(&m);
    c = c + lc;
    pthread_mutex_unlock(&m);

    pthread_exit(NULL);
}

int main(){

    pthread_t tid1, tid2;

    pthread_create(&tid1, NULL, count, (void *)0);  //primo thread che scansiona prima meta dei valori
    pthread_create(&tid2, NULL, count, (void *)(SIZE/2));   //secondo thread che scansiona la seconda meta dei valori

    // aspetta che thread finishe (attenzione: per ogni thread creato, ci deve essere un join che li aspetta per chiudere)
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    // spampa il risultato finale
    printf("%d\n", c);

    // elimina mutex per liberare lo spazio nella memoria
    pthread_mutex_destroy(&m);

    return 0;
}
