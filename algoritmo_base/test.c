#include<stdio.h>
#include"algoritmi_ordinamento.h"

#include <time.h>

struct timespec start, end;
double elapsed;


int main(){

    int arr[] = {5, 7, 4, 25, 19, 17, 1, 0, 10, 14, 6, 11, 9, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array originale: \n");
    printArray(arr, n);

    // 获取起始时间
    clock_gettime(CLOCK_MONOTONIC, &start);

    // --- 执行你的排序算法 ---
    
    insertionSort(arr, n);

    // ----------------------

    // 获取结束时间
    clock_gettime(CLOCK_MONOTONIC, &end);

    // 计算差值（秒 + 纳秒转化为秒）
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;

    printf("精确耗时: %.6f 秒\n", elapsed); // 显示到小数点后6位


    printf("Array ordinato (insertion sort): \n");
    printArray(arr, n);

    return 0;
}