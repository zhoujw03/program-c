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
        printf("CHILD/PIPPO: returned pid: %d\n", pid);
        printf("CHILD/PIPPO: pid: %5d ppid: %5d\n", getpid(), getppid());

        //il funzione execl fa in modo che le cose dentro le parentesi viene esequito direttamente sul terminale
        execl("./pluto", "pluto", "10", "20", NULL);
       
        //se il programma pluto non c'e', segue a stampare elemento sotto
        printf("CHILD/PIPPO: exec failed\n");
        abort();
    }
    else{
        //PARENT
        printf("PARENT/PIPPO: returned pid: %d\n", pid);
        printf("PARENT/PIPPO: pid: %5d ppid: %5d\n", getpid(), getppid());
        wait( &status );
        // con wifexited serve a verifiare se il programma e' terminato normalmente, se si ritorna 1, altrimenti 0
        if( WIFEXITED(status) != 0){
            printf("PARENT/PIPPO: got exit status: %d\n", WEXITSTATUS(status));
        }
        // Qui intercetta il segnale di terminazione e stampa il codice del seganle
        if( WIFSIGNALED(status) != 0){
            printf("PARENT/PIPPO: got signal: %d\n", WTERMSIG(status));
        }
        exit(0);
    }
}