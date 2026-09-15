/*Si sviluppi in C un programma che prende in ingresso un testo ed un array di caratteri e conta
il numeto di volte che ogni carettere dell'array appare nel testo. A tale sco[o si tenga presente
quanto segue:
    - Si supponga che il testo sia memorizzato in una variabile globale text.
    - L'array di catatteri da cercare e' passato al programma sulla linea di comando.
    - Si assuma che la dimensione massima di tale array sia pari a 8.
    - La ricerca deve essere organizzata per thread, uno per ogni carattere da ricercare.
    - Al termine della ricerca il programma stampa il numero totale di caratteri trovati.*/

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>

char *text = "This is the text to be searched...";

void* conta_carattere(void* arg){
    int num = 0;
    char simbolo = (char)arg;

    for (int i = 0; i < strlen(text); i++)
    {
        if(simbolo == text[i]){
            num++;
        }
    }
    return (void *)num;
}

int main(int argc, char* argv[]){

    pthread_t tid[8];
    int num[8];

    if(argc != 2){
        exit(1);
    }
    int nchar = strlen(argv[1]);
    for (int i = 0; i < nchar; i++)
    {
        pthread_create(&tid[i], NULL, conta_carattere, (void*)argv[1][i]);
    }

    for (int i = 0; i < nchar; i++ ){
        pthread_join(tid[i], (void **)&num[i]);
        printf("%c = %d\n",argv[1][i], num[i]);
    }
    
    return 0;
}