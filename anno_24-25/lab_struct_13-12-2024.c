  /*Menu
    inserimento un libro alla volta
    stampa libri
    ricerca per titolo
    ricerca per prezzo
    fine
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX_LIBRI 10

typedef struct
  {
      int aaaa; // anno
      int mm;   // mese
      int gg;   // giorno
}data;

typedef struct {
    char titolo[20];
    data data_pubblicazione;
    float prezzo;
    char autore[40];
    int gradimento[5];
}libro;


void inser_libro(libro bib[], int pos);
void stampa_libri(libro bib[], int num_libri);

int main (){

    libro biblio[MAX_LIBRI];
    int scelta;
    int indice_libro = 0;

    do{

        printf("\n Menu:\n");
        printf("\n1 inserimento un libro alla volta\n");
        printf("\n2 stampa libri\n");
        printf("\n3 ricerca per titolo\n");
        printf("\n4 ricerca per prezzo\n");
        printf("\n0 fine\n");
        printf("\ninserisci la scelta\n");

        scanf("%d", &scelta);

        switch(scelta){
            case 1:
                 if (indice_libro<MAX_LIBRI){
                    inser_libro(biblio, indice_libro);
                    indice_libro++;
                 }
                 else
                     printf("spazio insufficiente, libera un po' di spazio\n ");
                 break;
            case 2:
                if(indice_libro>0)
                    stampa_libri(biblio, indice_libro);
                else
                    printf("non sono ancora stati inseriti nessun libro nella bibliote\n");
                break;
            case 3:
                break;
            case 4:
                break;
            case 0:
                break;
            default:
                printf("scelta errata, riprova\n");
            }
    } while (scelta != 0);

    return 0;
}

void inser_libro(libro bib[], int pos){

    fflush(stdin);
    printf("inserisci il nome del libro\n");
    fgets(bib[pos].titolo, 20, stdin);
    printf("inserisci autore\n");
    fgets(bib[pos].autore, 40, stdin);
    printf("inserisci prezzo\n");
    scanf("%f", &bib[pos].prezzo);
    printf("inserisci il giorno\n");
    scanf("%d", &bib[pos].data_pubblicazione.gg);
    printf("inserisci il mese\n");
    scanf("%d", &bib[pos].data_pubblicazione.mm);
    printf("inserisci il anno\n");
    scanf("%d", &bib[pos].data_pubblicazione.aaaa);
}


void stampa_libri(libro bib[], int num_libri){
    int i;
    for (i = 0; i < num_libri;i++){
        printf("titolo: %s", bib[i].titolo);
        printf("autore: %s", bib[i].autore);
        printf("prezzo: %.2f\n", bib[i].prezzo);
        printf("data di pubblicazione: %d - %d - %d\n", bib[i].data_pubblicazione.gg,bib[i].data_pubblicazione.mm,bib[i].data_pubblicazione.aaaa);
    }
}