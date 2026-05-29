/*Scrivi un programma, tale programma deve ricevere i caratteri inseriti, fino quando incontra #,
dopo di che stampa numero di caratteri, spazi e numeri incontratti 
*/

#include<stdio.h>

int main(){

    int ch = 0;
    int space = 0;
    int num = 0;
    int special = 0;

    char c;
    printf("inserisci la frase:\n");

    while( (c = getchar())!='#'){
        // controlla se sono numeri
        if( c >='0' && c <='9'){
            num++;
        }       
        //controlla se sono catatteri
        else if( c >='a' && c <='z' || c >='A' && c <='Z' ){
            ch++;
        }
        //controlla se e' spazio
        else if (c == ' '){ 
            space++;
        }
        //se non sono nessuno dei sopra
        else{ 
            special++;
        }
    }

    printf("In totale hai premuto %d numeri\n", num);
    printf("In totale hai premuto %d caratteri\n", ch);
    printf("In totale hai premuto %d spazi\n", space);
    printf("In totale hai premuto %d caratteri speciali\n", special);
    return 0;
}