/*
Scrivere una struttura dati studente
studente(codice persona,nome e cognome, eta', voto);
inserire almeno 5 studenti
creare 3 funzioni:
- calcola e ritorna voto piu' alto
- calcola e ritorna voto medio
- calcola e ritorna percentuale di sufficienza
*/

#include<stdio.h>
#include<stdlib.h>

#define N 5

typedef struct {
    int codice_persona;
    char nome[20];
    int eta;
    int voto;
} studente_t;

void salva_studente(studente_t *stu);
void max_voto(studente_t *stu);
void mean_voto(studente_t *stu);
void perc_voto(studente_t *stu);

int main(){
    ////system("clear");

    int i = 0;
    studente_t *stu;

    stu = (studente_t *)malloc(N * sizeof(studente_t));

    while(1){
        printf("###################################\n");
        printf("#   1. salva dati studente        #\n");
        printf("#   2. voto piu' alto             #\n");
        printf("#   3. voto medio                 #\n");
        printf("#   4. percentuale sufficiente    #\n");
        printf("#   0.exit                        #\n");
        printf("###################################\n");


        int select;

        scanf("%d", &select);

        switch(select){
            case 1:
                salva_studente(&stu[i]);
                break;
            case 2:
                max_voto(&stu[0]);
                break;
            case 3:
                mean_voto(&stu[0]);
                break;
            case 4:
                perc_voto(&stu[0]);
                break;
            case 0:
                break;
            default:
                printf("seleziona il numero valido\n");
                break;
            }
            getchar();
            i++;
        if(select==0){
            break;
        }
    }
    free(stu);
    return 0;
}

void salva_studente(studente_t *stu){
    /*
    printf("inserici il codice persona:\n");
    scanf("%d", &stu->codice_persona);
    getchar();

    printf("inserici il nome:\n");
    fgets(stu->nome, sizeof(stu->nome), stdin);

    printf("inserici l'eta: \n");
    scanf("%d", &stu->eta);
    getchar();
    */
    printf("inserici il voto: \n");
    scanf("%d", &stu->voto);
    //getchar();

}

void max_voto(studente_t *stu){

    int i = 0;

    int max = 0;
    for (i = 0; i < N; i++)
    {
        if(stu[i].voto>max){
            max = stu[i].voto;
        }
    }

    printf("il voto piu' alto e': %d\n", max);
}
void mean_voto(studente_t *stu){

    int medio = 0;
    for (int i = 0; i < N; i++)
    {
        medio += stu[i].voto;

    }
    printf("il voto medio e': %d\n", medio/N);

}
void perc_voto(studente_t *stu){

    float num = 0;

    for (int i = 0; i < N; i++)
    {
        if(stu[i].voto>=60){
            num++;
        }
    }

    float percentuale = (num / N) * 100;
    printf("il %f %% dei persone sonno passati\n", percentuale);
}
