
#include<stdio.h>
#include<stdlib.h>

#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    pid_t pid;
    int status;

    pid = fork();
    if(pid == 0){
        //CHILD
        printf("CHILD: returned pid: %d\n", pid);
        printf("CHILD: pid: %5d ppid: %5d\n", getpid(), getppid());
        while(1)
            ;

        exit(33);
    }
    else{
        //PARENT
        printf("PARENT: returned pid: %d\n", pid);
        printf("PARENT: pid: %5d ppid: %5d\n", getpid(), getppid());
        wait( &status );
        // con wifexited serve a verifiare se il programma e' terminato normalmente, se si ritorna 1, altrimenti 0
        if( WIFEXITED(status) != 0){
            printf("PARENT: exit status: %d\n", WEXITSTATUS(status));
        }
        // Qui intercetta il segnale di terminazione e stampa il codice del seganle
        if( WIFSIGNALED(status) != 0){
            printf("PARENT: signal: %d\n", WTERMSIG(status));
        }
    }
}