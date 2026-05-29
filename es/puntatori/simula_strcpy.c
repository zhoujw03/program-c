// scrivere un programma in C che simula la funzione strcpy

#include<stdio.h>
#include<string.h>

char* my_strcpy(char* dest, const char* src){
    //int i = 0;

    char *tmp = dest;
    while (*src != '\0')
    {
        *dest = *src;       //copio il contenuto di src in dest
        src++;              // sposto puntatori di 1
        dest++;
    }
    *dest = '\0';           // ATTENZIONE: si deve ricordare di aggiungere \0
    return tmp;


    /*   while (*dest++ = *src++)
    {
                copio il contenuto di src in dest versione piu semplice 
                ma un po piu complesso da comprendere

                in questo caso non c'e bisogno di aggiungere \0 noi alla fine
    }*/
}

int main(){
    char dest[15];
    const char *arr = "ciao";

    char *ret1 = strcpy(dest, arr);
    char *ret2 = my_strcpy(dest, arr);

    printf("%s\n", ret1);
    printf("%s\n", ret2);

    return 0;
}
