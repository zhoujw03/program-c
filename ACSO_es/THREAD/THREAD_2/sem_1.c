// problema del sicronizzazione e uso dei semafori 
// funziona per sistema MacOs

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<pthread.h>
//#include<semaphore.h>
#include<dispatch/dispatch.h>

#define N 10

int counter = 0;
dispatch_semaphore_t sem_inc;
dispatch_semaphore_t sem_dec;
//sem_t semi;
//sem_t semd;

// Thread functions
void* inc(void* arg)
{
    for (int i = 0; i < N; i++ )
    {
        dispatch_semaphore_wait(sem_dec, DISPATCH_TIME_FOREVER);

        //sem_wait(&semd);
        counter++;
        printf(" i counter = %8d\n", counter);
        //usleep(100);
        
        dispatch_semaphore_signal(sem_inc);
        //sem_post(&semi);
    }
    pthread_exit(NULL);
}

void* dec(void* arg)
{
    for (int i = 0; i < N; i++)
    {
        dispatch_semaphore_wait(sem_inc, DISPATCH_TIME_FOREVER);

        //sem_wait(&semi);
        counter--;
        printf("d counter = %8d\n", counter);
        //usleep(100);
        
        dispatch_semaphore_signal(sem_dec);
        //sem_post(&semd);
    }
    pthread_exit(NULL);
}

// Main
int main(int argc, char *argv[]){
    pthread_t tid1, tid2;

    sem_inc = dispatch_semaphore_create(0);
    sem_dec = dispatch_semaphore_create(1);

    //semaforo
    //sem_init(&semi, 0, 0);
    //sem_init(&semd, 0, 1);

    //Creates thread
    pthread_create(&tid1, NULL, inc, NULL);
    pthread_create(&tid2, NULL, dec, NULL);

    // Waits thread termination
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    // libera spazio
    dispatch_release(sem_inc);
    dispatch_release(sem_dec);
    // Exits
    exit(0);
}