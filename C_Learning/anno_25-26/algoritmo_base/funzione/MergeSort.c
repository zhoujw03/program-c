/* Merge Sort
Divide l’array in due metà, ordina ricorsivamente le due metà e poi le fonde.

Idea:
dividi
ordina le due parti
unisci le due parti ordinate

Complessità:
Tempo: O(n log n)
Spazio: O(n)
*/
#include<stdio.h>
#include<string.h>
#include"../algoritmi_ordinamento.h"

void merge(int arr[], int left, int mean, int right) {

    // n1 = numero di elementi nella parte sinistra
    // n2 = numero di elementi nella parte destra
    int n1 = mean - left + 1;
    int n2 = right - mean;

    // Creo due array temporanei:
    // l[] contiene gli elementi da arr[left] a arr[mean]
    // r[] contiene gli elementi da arr[mean + 1] a arr[right]
    int l[n1], r[n2];

    // Copio la parte sinistra dell'array originale in l[]
    for (int i = 0; i < n1; i++) {
        l[i] = arr[left + i];
    }

    // Copio la parte destra dell'array originale in r[]
    for (int j = 0; j < n2; j++) {
        r[j] = arr[mean + 1 + j];
    }

    // i scorre l'array temporaneo sinistro l[]
    // j scorre l'array temporaneo destro r[]
    int i = 0;
    int j = 0;

    // k indica la posizione corrente dell'array originale arr[]
    // dove devo inserire il prossimo elemento ordinato
    for (int k = left; k <= right; k++) {

        // Se tutti gli elementi di l[] sono già stati copiati,
        // allora posso solo prendere elementi da r[]
        if (i == n1) {
            arr[k] = r[j];
            j++;
        }

        // Se tutti gli elementi di r[] sono già stati copiati,
        // allora posso solo prendere elementi da l[]
        else if (j == n2) {
            arr[k] = l[i];
            i++;
        }

        // Se entrambi gli array hanno ancora elementi,
        // confronto il più piccolo elemento rimasto di l[] e r[]
        // e copio il minore dentro arr[]
        else if (l[i] <= r[j]) {
            arr[k] = l[i];
            i++;
        }

        // Se r[j] è più piccolo di l[i],
        // copio r[j] dentro arr[]
        else {
            arr[k] = r[j];
            j++;
        }
    }
}

void merge_sort(int arr[], int left, int right) {

    // Caso base:
    // se left >= right, la porzione ha 0 o 1 elemento,
    // quindi è già ordinata
    if (left < right) {

        // Calcolo l'indice centrale per dividere l'array in due parti
        int mean = (left + right) / 2;

        // Ordino ricorsivamente la parte sinistra
        merge_sort(arr, left, mean);

        // Ordino ricorsivamente la parte destra
        merge_sort(arr, mean + 1, right);

        // Unisco le due parti già ordinate
        // ottenendo una porzione ordinata da left a right
        merge(arr, left, mean, right);
    }
}

