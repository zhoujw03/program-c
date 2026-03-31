// introduzione thread 
// creazione e passaggio di argomenti

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>

// Thread function
void* my_task(void *arg){
    printf("THREAD: execution stated\n");
    printf("THREAD: argument is: %ld\n", (long int)arg);
    printf("THREAD: pid: %d  tid: %ld\n", getpid(), (long int)pthread_self());
    printf("THREAD: terminated\n");
    pthread_exit((void*)456);
}

int main(int argc, char **argv){
    pthread_t tid;
    int status;
    long int argument;
    long int retval;

    printf("MAIN: pid: %d  tid: %ld\n", getpid(), (long int) pthread_self());

    //creates a thread and executes my_task in the thread
    argument = 123;
    status = pthread_create(&tid, NULL, my_task, (void *)argument);
    printf("MAIN: creating new thread %ld\n", (long int) tid);

    if (status != 0)
    {
        printf("MAIN: error creating thread\n");
        exit(1);
    }

    printf("MAIN: waiting thread termination\n");

    //waits thread termination
    pthread_join(tid, (void *)&retval);
    printf("MAIN: thread returned %ld\n", retval);

    printf("MAIN: thread terminated\n");

    exit(5);
}