//introduzione funzione fork() e wait()
#include<stdio.h>
#include<stdlib.h>

#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    pid_t pid;
    
    pid = fork();
    if(pid == 0){
        //CHILD
        printf("CHILD: returned pid: %d\n", pid);
        printf("CHILD: pid: %5d ppid: %5d\n", getpid(), getppid());
        exit(0);
    }
    else{
        //PARENT
        printf("PARENT: returned pid: %d\n", pid);
        printf("PARENT: pid: %5d ppid: %5d\n", getpid(), getppid());
        wait(NULL);
    }
    exit(10);
}