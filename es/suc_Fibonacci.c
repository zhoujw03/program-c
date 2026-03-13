//scrivere una funzione ricorsiva, che trova n-esimo numero della succesione di fibonacci
#include<stdio.h>

int fib(int a) {
    if(1 == a || 2 == a){
        return 1;
    }
    return fib(a - 1) + fib(a - 2);
}

int main(){
    int a ;
    scanf("%d", &a);
    int b = fib(a);
    printf("%d", b);

    return 0;
}