#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void manu(){
    printf("***********************\n");
    printf("*******  1. play  *****\n");
    printf("*******  0. exit  *****\n");
    printf("***********************\n");
}

void game(){
    int a = rand() % 100;
    int num;
    int i = 0;
    printf("hai 5 tentativi\n");
    printf("scegli un numero tra 0~99: ");
    for (i = 5; i > 0; i--)
    {
        scanf("%d", &num);
        if (num < a){
            printf("numero troppo piccolo\n");
            printf("ti rimane %d tentativi\n", i-1);
        }
        else if(num > a){
            printf("numero troppo grande\n");
            printf("ti rimane %d tentativi\n", i-1);
        }
        else{
            printf("hai indovinato\n\n");
            break;
        }
        }
    if(i==0){
        printf("hai finiti tentativi\n");
        printf("il numero era %d\n\n", a);
    }
        
}

int main (){

    int scelta;
    srand(time(NULL));
    do{
        manu();
        printf("inserisci : ");
        scanf("%d", &scelta);
        switch(scelta){
            case 1:
                system("clear");
                printf("inizia il gioco\n");
                game();
                break;
            case 0:
                break;
            default:
                printf("numero errato\n");
            }

    } while (scelta != 0);

    return 0;
}