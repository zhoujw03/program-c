#include<stdio.h>

//operazione di somma e differenza tra puntatori

int main(){

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    // salva indirizzo di arr[0], nel puntatore di nome p
    int *p = &arr[0];

    printf("%p\n", &arr[0]);
    printf("%p\n", p);      //possiamo vedere che dopo esecuzione il valore finale stampato e' lo stesso

    printf("==================\n");

    // Stampa l'indirizzo di memoria del secondo elemento dell'array (indice 1)
    // L'operatore '&' restituisce l'indirizzo della variabile che lo segue
    printf("%p\n", &arr[1]);

    // Stampa l'indirizzo contenuto nel puntatore 'p' incrementato di 1
    // L'aritmetica dei puntatori sposta l'indirizzo di "1 unità" (es. 4 byte per un int)
    printf("%p\n", p + 1);

    printf("==================\n");
    
    // Stampa il valore memorizzato nel secondo elemento dell'array
    printf("arr[1] = %d\n", arr[1]);

    // Stampa il valore puntato dall'indirizzo (p + 1)
    // L'operatore '*' (dereferenziazione) serve a leggere il contenuto di un indirizzo
    printf("*(p+1) = %d\n", *(p + 1));

    // Se p è un puntatore a char (1 byte)
    // L'indirizzo aumenta di solo 1 rispetto a p

    // Se p è un puntatore a short (2 byte)
    // L'indirizzo aumenta di 2 rispetto a p


    return 0;
}