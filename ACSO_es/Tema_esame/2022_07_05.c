/*
Si scriva un programma in C che prende in ingresso due vettori dati e scamnia il loro contenuto.
Scrivere una funzione swap() ed il programma main() in modo da parallelizzare l'esecuzione 
su due thread concorrenti
*/

#include<stdio.h>
#include<pthread.h>

#define N 10

int a[N] = {1, 3, 5, 7, 9, 13, 15, 17, 19, 20};
int b[N] = {11, 13, 15, 17, 19, 113, 115, 117, 119, 120};

void* swap(void* arg){
    int n = (int)arg;
    int mean = N / 2;

    int t;
    // scambia i contenuti dell'array
    for (int i = n * mean; i < n * mean + mean; i++)
    {
        t = a[i];
        a[i] = b[i];
        b[i] = t;
    }
    return 0;
}

int main(){
    pthread_t tid1, tid2;
    //crea 2 thread
    pthread_create(&tid1, NULL, swap, (void *)0);
    pthread_create(&tid2, NULL, swap, (void *)1);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    for (int i = 0; i < N; i++ ){
        printf("a[%d] = %d\tb[%d] = %d\n", i, a[i], i, b[i]);
    }
    return 0;
}