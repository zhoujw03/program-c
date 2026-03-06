/*gestire vattura di un concessionario
gestisce fino a 50 vettura
manu:
    1.inserimento vettura
    2.stampare 
    3.
    4.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// costanti
#define MAXLEN 20
#define DIM 5

// caratteristica della vettura
typedef struct {
    float valore;
    int cilindrata;
    char modello[MAXLEN];
} vettura;

void inser(vettura veicoli[], int pos);
void stampa(vettura veicoli[], int pos);
int stampa_modelli(vettura veicoli[], int pos, char mod[]);

int main(){
    vettura concessionario[DIM];
    int scelta;
    int posizione = 0;
    int i;
    char modello_cercato;
    int num_modelli;

    do{

        printf("\n Menu\n");
        printf("\n 1 inserimento \n");
        printf("\n 2 stampa singola vettura \n");
        printf("\n 3 stampa totale delle vetture\n");
        printf("\n 4 stampa modello \n");
        printf("\n 5 modello e cilindrata con valore < val\n");
        printf("\n 0 fine\n");
        printf(" scelta\n");
        scanf("%d", &scelta);

        switch(scelta){
            case 1:
                if(posizione<DIM){
                    inser(concessionario, posizione);
                    posizione++;
                 }
                 else{
                     printf("non c'e piu posti liberi nel concessionario\n");
                 }
                 break;
            case 2:
                break;
            case 3:
                if(posizione > 0){
                   for (i = 0; i < posizione; i++){
                       stampa(concessionario, i);
                   }
                }
                else{
                    printf("non sono stati ancore inserite vetture\n");
                }
                    break;
            case 4:
                if(posizione>0){
                    fflush(stdin);
                    printf("inserisci modello da cercare");
                    fgets(&modello_cercato, MAXLEN, stdin);
                    num_modelli = stampa_modelli(concessionario, posizione, &modello_cercato);
                    if (num_modelli==0)
                        printf("non e' presente il modello cercato");
                    else
                        printf("sono state trovare %d vetture del modello", num_modelli);
                }
                else
                    printf("non ha inserito nessun dato");
                break;
            case 5:
                break;
            case 0:
                break;
            default:
                printf("scelta errata\n");
            }
    } while (scelta != 0);
    
    return 0;
} //fine main

// funzione per inserimento dati
void inser(vettura veicoli[], int pos){
    fflush(stdin);
    printf("inserisci il modello\n");
   // scanf("%s", veicoli[pos].modello);
    fgets(veicoli[pos].modello,MAXLEN,stdin);

    printf("inserichi cilindrata\n");
    scanf("%d", &veicoli[pos].cilindrata);

    printf("inserisci il prezzo della vettura\n");
    scanf("%f", &veicoli[pos].valore);

}

// stampare i dati 
void stampa(vettura veicoli[], int pos){
    printf("modello: %s\n", veicoli[pos].modello);
    printf("cilindrata: %d\n", veicoli[pos].cilindrata);
    printf("prezzo: %.2f\n", veicoli[pos].valore);
}

int stampa_modelli(vettura veicoli[], int pos, char mod[]){
    int i;
    int conta_modelli = 0;
    for (i = 0; i < pos; i++)
    {
        if(strcmp(veicoli[i].modello, mod)==0){
            stampa(veicoli, i);
            conta_modelli++;
        }
    }
    return conta_modelli;
}


