#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define ROWS 4
#define COLS 5

unsigned int Matrix[ROWS][COLS] = {10, 2, 23, 46, 51, 6, 7, 8, 9, 0, 11, 14, 43, 56, 78, 73, 21, 36, 98, 40};


void* numMax(void* arg)
{
    int rowmax = 0;
    int *row = (int *)arg;
    for (int i = 0; i < COLS; i++ ){
        rowmax = (row[i] > rowmax) ? row[i] : rowmax;
    }
    return (void*)rowmax;
}

int main(){
    pthread_t tid[ROWS];

    //crea numero di thread quanto le righe della matrice
    for (int i = 0; i < ROWS; i++ ){
        pthread_create(&tid[i], NULL, numMax, (void*) Matrix[i]);
    }

    int max = 0;
    int rowmax = 0;
    for (int i = 0; i < ROWS; i++ ){
        pthread_join(tid[i], (void**)&rowmax); //casto puntatore void** per ricevere valore ritornato
        max = max > rowmax ? max : rowmax;  // confronta tra valori tornato 
    }
    printf("max number is: %d", max);
    exit(0);
}