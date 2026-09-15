/* L'Insertion Sort (ordinamento per inserimento) è un algoritmo di ordinamento 

Come funziona (Il Concetto)
L'idea base è quella di dividere virtualmente l'elenco in due parti: una parte già ordinata e una parte ancora da ordinare.

    1. L'algoritmo parte dal secondo elemento (considerando il primo come già "ordinato").
    2. Prende l'elemento corrente (chiamato chiave o key).
    3. Lo confronta con gli elementi alla sua sinistra (nella parte ordinata).
    4. Sposta verso destra tutti gli elementi che sono più grandi della chiave per "fare spazio".
    5. Inserisce la chiave nella posizione corretta. */

#include<stdio.h>
#include<string.h>
#include"../algoritmi_ordinamento.h"

void insertionSort(int arr[], int n){

    int key, i, j;

    for (j = 1; j < n; j++){
        key = arr[j];   //elemento da inserire 
        i = j - 1;     
        
        /* Sposta gli elementi di arr[0..i-1] che sono
           maggiori della key di una posizione a destra */
        while(i>=0 && arr[i]>key){
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        // Inserimento della key nella posizione corretta
        arr[i + 1] = key;
    }

}

