/* 
Heap sort è un algoritmo di ordinamento basato sulla struttura dati heap, di solito un max-heap.
Un max-heap è un albero binario quasi completo in cui ogni nodo ha valore maggiore o uguale dei suoi figli. 
In questo modo, l’elemento massimo si trova sempre nella radice.
L’idea di heap sort è:
trasformare l’array in un max-heap;
scambiare il primo elemento, cioè il massimo, con l’ultimo elemento dell’array;
ridurre la dimensione dell’heap, perché l’ultimo elemento è già nella posizione corretta;
ripristinare la proprietà di heap;
ripetere finché tutto l’array è ordinato.
*/

#include<stdio.h>
#include"../algoritmi_ordinamento.h"

void swap(int *a, int*b){
    // scambio due elementi del array
    int t= *a;
    *a = *b;
    *b = t;
}

// Ripristina la proprietà di max-heap
// n = dimensione attuale dell'heap
// i = indice del nodo da controllare
void max_heaify(int arr[], int dimensione, int i){

    // Suppongo che il nodo i sia il più grande
    int max = i;

    // Indice del figlio sinistro
    int left = 2 * i + 1;

    // Indice del figlio destro
    int right = (2 * i) + 2;
    // Se il figlio sinistro esiste ed è maggiore del nodo corrente
    if(left < dimensione && arr[left] > arr[max]){
        max = left;
    }
    // Se il figlio destro esiste ed è maggiore del più grande trovato finora
    if(right < dimensione && arr[right] > arr[max]){
        max = right;
    }

    // Se il nodo più grande non è i, allora devo scambiare
    if(max != i){
        swap(&arr[i], &arr[max]);
        // Dopo lo scambio, continuo a sistemare il sottoalbero
        max_heaify(arr, dimensione, max);
    }
}


void heap_sort(int arr[], int dimensione){

    // 1. Costruisco il max-heap
    // Parto dall'ultimo nodo interno fino alla radice
    for (int i = dimensione / 2 - 1; i >= 0; i--)
    {
        max_heaify(arr, dimensione, i);
    }
    // 2. Estraggo il massimo uno alla volta
    for (int i = dimensione - 1; i > 0; i-- ){
        swap(&arr[0], &arr[i]);
        // Ora l'ultima posizione è ordinata,
        // quindi riduco la dimensione dell'heap a i
        max_heaify(arr, i, 0);
    }
}
