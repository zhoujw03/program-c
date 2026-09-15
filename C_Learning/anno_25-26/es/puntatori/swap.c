//scrivere una finzione in c, con la funzione di scambia tra due variabile

#include<stdio.h>

//definizione della funzione
void swap(int *a,int *b){
    int temp = *a;      //salva il valore di a in una variabile temporaneo
    *a = *b;            // mette valore di b in a
    *b = temp;          //mette il valore salvato (il vecchio a) nel b
}

int main(){
    int a = 10;
    int b = 20;
    printf("a = %d, b = %d\n", a, b);

    // Passiamo gli indirizzi delle variabili usando &
    swap(&a, &b);

    printf("a = %d, b = %d\n", a, b);
}