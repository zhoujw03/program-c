//con inputo nel terminale ./pippo 4 stampa （numero minore di 26)
// ./pluto A B C D 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

char **alfabeto = NULL;

int main(int argc,char **argv){
    pid_t pid;
    int status;
    char *p;
    int num = strtol(argv[1], &p, 10)+1;

    alfabeto = (char **)malloc((num + 1) * sizeof(char *));
    alfabeto[0] = strdup("./pluto");
    
    for (int j = 1; j < num; j++ ){
        char lettera[] = {64 + j};
        alfabeto[j] = strdup(lettera);
    }

    pid = fork();
    if(pid == 0){
        //CHILD
        execv("./pluto", alfabeto);
        abort();
    }
    else{
        //PARENT
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
        free(alfabeto);
        alfabeto = NULL;
        return 0;
}