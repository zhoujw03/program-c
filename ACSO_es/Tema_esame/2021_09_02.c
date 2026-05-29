/*
Si sviluppino in C il programma principale main() e due funzioni step() ed action() secondo le
seguenti specifiche:

Le due funzioni devonoessere eseguite in due thread separati.
1. La funzione step() svolge le seguenti azioni:
    - Esegue un ciclo in cui incrementa il valore di un contatore CNT ad ogni iterazione
    - Quando il valore corrente del contatore e' un multiplo di 10, viene eseguita le funzione action()
    - Il ciclo continua finche' il contatore rimane minore di 1000.

2. La funzione action()
    - Esegue un ciclo in cui si sospende in attesa di essere attivata dalla funzione step()
    - Quando attivata somma al contatore CNT un valore casuale compreso tra 0 e 5,
      quindi si sospende nuovamente.
    - La finzione termina quando il contatore reggiunge il valore 1000.

3. Il programma principale attende la terminazione dei due thread e stampa il numero di 
iterazioni che sono state eseguire da ognuna delle due funzioni.
*/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<dispatch/dispatch.h>

int CNT = 0;

//sem_t sem_action;   // dichiara semaphori
//sem_t sem_step;

dispatch_semaphore_t sem_action;
dispatch_semaphore_t sem_step;

int loop_action, loop_step;

void *step(void *arg)
{
    
    loop_step = 0;
    while(CNT<1000){
        //sem_wait(&sem_action);  // aspetta che funzione action finisce
        dispatch_semaphore_wait(sem_action, DISPATCH_TIME_FOREVER);

        // incrementa contatore del loop e CNT
        CNT++;
        loop_step++;
        if (CNT % 10 == 0)  // se CNT e' divisibile per 10 fa iniziare la funzione action
        {
            //sem_post(&sem_step);
            dispatch_semaphore_signal(sem_step);
        }
        else{ // aumenta sem_action per non bloccare la prossimo ciclo
            dispatch_semaphore_signal(sem_action);
            //sem_post(&sem_action);
        }
    }
    pthread_exit(NULL);
}

void* action(void* arg){
    loop_action = 0;
    while(CNT<1000){
        //sem_wait(&sem_step);
        dispatch_semaphore_wait(sem_step, DISPATCH_TIME_FOREVER);

        // incrementa contatore del loop e CNT
        CNT += rand() % 6;
        loop_action++;
        //sem_post(&sem_action);
        dispatch_semaphore_signal(sem_action);

    }
    pthread_exit(NULL);
}

int main(){
    pthread_t tidS, tidA;

    //sem_init(&sem_step, 0, 0);
    //sem_init(&sem_action, 0, 1);

    sem_step = dispatch_semaphore_create(0);
    sem_action = dispatch_semaphore_create(1);

    pthread_create(&tidS, NULL, step, NULL);
    pthread_create(&tidA, NULL, action, NULL);

    pthread_join(tidS, NULL);
    pthread_join(tidA, NULL);

    printf("numero di iterazione step: %d\n", loop_step);
    printf("numero di iterazione action: %d\n", loop_action);

    //sem_destroy(&sem_action);
    //sem_destroy(&sem_step);

    dispatch_release(sem_action);
    dispatch_release(sem_step);

    return 0;
}