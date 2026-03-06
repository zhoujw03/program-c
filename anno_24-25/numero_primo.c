#include<stdio.h>

void individua(int num){
    int i = 0;
    for (i = 2; i < num;i++){
        if(num % i ==0){
            printf("non è primo");
            break;
        }
    }
    if(num/i==1)
        printf("è primo");
}

int main(){

    int a;
    printf("inserire un numero");
    scanf("%d", &a);
    individua(a);
    return 0;
}