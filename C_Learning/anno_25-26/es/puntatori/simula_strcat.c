// scrivere un programma in C che simula la funzione strcat
//char *strcat(char *dest, const char *src);


#include<stdio.h>
#include<string.h>

char *my_strcat(char *dest, const char *src){

    char *tmp = dest;

    while(*dest!= '\0'){        //scorrere fino alla fine di questa stringa
        dest++;
    }
    while(*src != '\0'){        // aggiungere i contenuti della seconda stringa nella prima
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return tmp;
}

int main(){

    char dest[20] = "Hello";
    const char *src = " World!";
    
    //strcat(dest, src);
    char *ret = my_strcat(dest, src);

    printf("%s\n", ret);

    return 0;
}