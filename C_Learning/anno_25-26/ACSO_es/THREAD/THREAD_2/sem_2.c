
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<pthread.h>
#include<semaphore.h>

#define N 10

int counter = 0;
sem_t semi;
sem_t semd;

// Thread functions
void* inc(void* arg)
{
    for (int i = 0; i < N; i++ )
    {
        sem_wait(&semd);
        counter++;
        printf(" i counter = %8d\n", counter);
        //usleep(100);
        sem_post(&semi);
    }
    pthread_exit(NULL);
}

void* dec(void* arg)
{
    for (int i = 0; i < N; i++)
    {
        sem_wait(&semi);
        counter--;
        printf("d counter = %8d\n", counter);
        //usleep(100);
        sem_post(&semd);
    }
    pthread_exit(NULL);
}

// Main
int main(int argc, char *argv[]){
    pthread_t tid1, tid2;

    //semaforo
    sem_init(&semi, 0, 0);
    sem_init(&semd, 0, 0);

    //Creates thread
    pthread_create(&tid1, NULL, inc, NULL);
    pthread_create(&tid2, NULL, dec, NULL);

    //starts first thread
    sem_post(&semd);

    // Waits thread termination
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    // Exits
    exit(0);
}