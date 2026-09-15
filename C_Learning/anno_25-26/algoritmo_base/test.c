#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include"algoritmi_ordinamento.h"

void genera_array_casuale(int arr[], int dimensione, int min, int max) {
    for (int i = 0; i < dimensione; i++) {
        // Formula per limitare il numero nell'intervallo [min, max]
        arr[i] = min + rand() % (max - min + 1);
    }
}

struct timespec start, end;
double elapsed;

void conta_tempo(int arr[], int dimensione){

    int n;
    printf("scegli algoritmo di ordinamento da usare\n");
    printf("1. insertion sort\n");
    printf("2. merge sort\n");
    printf("3. heap sort\n");

    scanf("%d", &n);

    // 获取起始时间
    clock_gettime(CLOCK_MONOTONIC, &start);

    // --- 执行你的排序算法 ---
    switch (n)
    {
    case 1:
        insertionSort(arr, dimensione);
        printf("Array ordinato (insertion sort): \n");
        break; 
    case 2:
        merge_sort(arr, 0, dimensione);
        printf("Array ordinato (merge sort): \n");
        break;
    case 3:
        heap_sort(arr, dimensione);
        printf("Array ordinato (heap sort): \n");
        break;
    
    default:
        printf("valore inserito errato!!!\n");
        break;
    }

    // ----------------------

    // 获取结束时间
    clock_gettime(CLOCK_MONOTONIC, &end);

    // 计算差值（秒 + 纳秒转化为秒）
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;

    printf("精确耗时: %.6f 秒\n", elapsed); // 显示到小数点后6位
    
}


int main(){

    int n = 1000;
    int arr[n];

    // Inizializza il generatore di numeri casuali usando il tempo corrente
    srand(time(NULL));

    printf("Array originale: \n");
    // Genera numeri casuali compresi tra 1 e 100
    genera_array_casuale(arr, n, 1, 100000);
    stampa_array(arr, n);

    conta_tempo(arr, n);


    stampa_array(arr, n);

    return 0;
}
