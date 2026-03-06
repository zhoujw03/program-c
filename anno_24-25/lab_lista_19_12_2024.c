#include<stdio.h>
#include<stdlib.h>

#define MAX_L 30


typedef struct{
    char nome[MAX_L];
    float h;
} persona_t;

typedef struct El{
    persona_t persona;
    struct El *next;
}elem_persona_t;

typedef elem_persona_t *lista_pesrsona_t;

void inizializza(lista_pesrsona_t *list){
    *list = NULL;
}

int main(){
    lista_pesrsona_t list;
    list = NULL;
    visualizza(&list);

    return 0;
}