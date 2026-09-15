#include<stdio.h>

// la dereferenziazione e l'ordine dei byte
int main(){
    int n = 0x11223344;
    int *p = &n;
    printf("%x \n", *p);

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *pa = &arr[0];
    // Immaginiamo che arr[0] sia un int con valore 0x12345678 (esadecimale)
    // Un puntatore 'int *p' vede l'intero numero.
    // Un puntatore 'char *p_byte' vede un singolo byte alla volta.

    // 1. DEREFERENZIAZIONE: Accedere al "contenuto"
    // L'operatore '*' va all'indirizzo e preleva il valore.
    printf("Valore intero: %d\n", *pa); 

    // 2. BYTE ORDER (Endianness): Come i byte sono salvati in memoria
    // In un sistema "Little-Endian", il byte meno significativo (LSB) 
    // viene salvato all'indirizzo più basso.
    arr[0] = 0x12345678;
    unsigned char *p_byte = (unsigned char *)&arr[0];

    // Se arr[0] = 0x12345678:
    // p_byte[0] (indirizzo base)     -> 0x78  (Byte meno significativo)
    // p_byte[1] (indirizzo base + 1) -> 0x56
    // p_byte[2] (indirizzo base + 2) -> 0x34
    // p_byte[3] (indirizzo base + 3) -> 0x12  (Byte più significativo)

    printf("Primo byte in memoria: %02x\n", *p_byte);

    return 0;
}