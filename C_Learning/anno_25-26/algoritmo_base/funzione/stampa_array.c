#include<stdio.h>
#include"../algoritmi_ordinamento.h"

void stampa_array(int arr[], int dimensione){
    
    for (int i = 0; i < dimensione; i++ ){
        printf("%d ", arr[i]);
    }
    printf("\n");
}