/*Scrivere un programma che realizza la seguente struttura di processi:
             - (R) 
           /
(P)- (Q) -
           \
             - (S) - (T)
Ogni processo stampa il proprio nome, il proprio PID,il PID del proprio padre e termina
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    pid_t pidQ, pidR, pidS, pidT;
    int status[] = {1, 2, 3, 4};
    pidQ = fork();

    if(pidQ == 0){
        printf("Q PID: %d, PARENT P PID: %d \n", getpid(), getppid());
        pidR = fork();
        pidS = fork();
        if (pidR == 0)
        {
            printf("R PID: %d, PARENT Q PID: %d \n", getpid(), getppid());
            printf("processo R termina\n");
            exit(0);
        }
        if (pidS == 0)
        {
            printf("S PID: %d, PARENT Q PID: %d \n", getpid(), getppid());
            pidT = fork();
            if (pidT == 0)
            {
                printf("T PID: %d, PARENT S PID: %d \n", getpid(), getppid());
                printf("processo T termina\n");
                exit(0);
            }
            else{
                waitpid(pidT, &status[4], 0);
                exit(0);
            }
        }
        waitpid(pidS, &status[2], 0);
        waitpid(pidQ, &status[3], 0);

        printf("processo S termina\n");
        printf("processo Q termina\n");
        exit(0);
    }
    else{
        printf("PARENT P PID: %d, CHILD Q PID: %d \n", getpid(), pidQ);
        waitpid(pidQ, &status[1], 0);
        printf("programma P termina\n");
        exit(0);
    }
    return 0;
}