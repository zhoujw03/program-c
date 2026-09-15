#include<stdio.h>

typedef int (*gt_t)(void *, void *);

int compare(void *a, void *b, gt_t func);
int gt_int(void *a, void *b);
int gt_float(void *a, void *b);

int compare(void *a, void *b, gt_t func){
    return (*func)(a, b);
}

int gt_int(void *a, void *b){
    return *(int*)a > *(int*)b ? 1 : 0;
}

int gt_float(void *a, void *b){
    return *(float *)a > *(float *)b ? 1 : 0;
}

int main(){
    int a = 10, b = 20;
    if(compare((void*)&a,(void*)&b, gt_int) == 1){
        printf("%d > %d\n", a, b);
    }
    else{
        printf("%d < %d\n", a, b);
    }

    float x = 1.1, y = 2.1;
    if(compare((void*)&x,(void*)&y, gt_float) == 1){
        printf("%f > %f\n", x, y);
    }
    else{
        printf("%f < %f\n", x, y);
    }

    return 0;
}