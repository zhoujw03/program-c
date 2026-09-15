//创建两个有序数列，然后将两个数组合并成一个有序数列并输出
//例子：
/*
输入：5 6
    1 3 7 9 13
    2 8 10 12 17 20

输出：1 2 3 7 8 9 10 12 13 17 20
*/
#include<stdio.h>

int main(){
    int n ,k;
    scanf("%d %d", &n, &k);
    
    int arr1[100] = {0};
    int arr2[100] = {0};
    // 初始化数组
    for (int i = 0; i < n; i++)
    {
       scanf("%d" ,&arr1[i]);
    }
    for (int j = 0; j < k; j++)
    {
       scanf("%d" ,&arr2[j]);
    }
    
    int i = 0;
    int j = 0;

    //判断哪个数组里的数字小
    while (i< n && j < k)
    {
        if(arr1[i]<arr2[j]){
            printf("%d ", arr1[i]);
            i++;
        }
        else{
            printf("%d ", arr2[j]);
            j++;
        }
    }

    // 把剩下没输出的输出
    while(i<n){
        printf("%d ", arr1[i]);
        i++;
    }

    while(j<k){
        printf("%d ", arr2[j]);
        j++;
    }
    return 0;
}