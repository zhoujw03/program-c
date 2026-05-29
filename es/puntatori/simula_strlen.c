// scrivere un programma in C che simula la funzione strlen

#include<stdio.h>

size_t my_strlen(const char *str){
    
    if(str == NULL){
        printf("non presente nessuna stringa \n");
        return 0;
    }

    size_t count = 0;

    while(*str){
        count++;
        str++;
    }

    return count;
}

int main(){
    const char *s = "Hello, world!";
    int len = my_strlen(s);

    printf("%s\n", s);
    printf("lunghezza della stringa e': %d\n", len);

    return 0;
}