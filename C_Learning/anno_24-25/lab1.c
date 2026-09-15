#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#define DIM 10

void inserimento(int v[],int nelementi);
void stampa(int v[],int nelementi);
int calcolapunti(int v[], int nelementi);



int main(){
    srand(time(0));
    int scelta;
    int casa[DIM];
    int trasferta[DIM];
    do{
        printf("\n Menu\n");
        printf("\n1 Inserisci punti squadra casa\n");
        printf("\n2 Inserisci punti squadra trasferta\n");
        printf("\n3 calcola punti di una squadra casa\n");
        printf("\n4 calcola punti di una squadra trasferta\n");
        printf("\n0 Fine\n");

        printf("\nscelta:\n");
        scanf("%d", &scelta);

        switch(scelta){
            case 1:
                inserimento(casa,DIM);
                stampa(casa,DIM);
                break;
            case 2:
                inserimento(trasferta,DIM);
                stampa(trasferta,DIM);
                break;
            case 3:
                printf("i punteggio sono: %d",calcolapunti(casa, DIM));
                break;
            case 4:
                printf("i punteggio sono: %d", calcolapunti(trasferta, DIM));
                break;
            case 0:
                break;
            default:
                printf("errore\n");
            }

    } while (scelta != 0);

    return 0;
} 

void inserimento(int v[],int nelementi){
    int i;
    for (i = 0; i < 10; i++) {
        v[i] = rand() % 4;
    }
 }
 void stampa(int v[],int nelementi){
    int i;
    for (i = 0; i < 10; i++) {
        printf("%d - ",v[i]);
    }
    printf("\n");
 }

 int calcolapunti(int v[], int nelementi){
     int i;
     int somma = 0;
     for (i = 0; i < nelementi; i++)
     {
         somma = somma + v[i];
     }
     return somma;
 }