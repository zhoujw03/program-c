//caso creazione processo zombie

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    pid_t pid;
    int status;

    pid = fork();
    if( pid == 0 ){
        //CHILD
        printf("CHILD: return pid: %d\n", pid);
        printf("CHILD: pid: %5d  ppid: %5d\n", getpid(), getppid());
        printf("CHILD: sleeping ...\n");
        sleep(30);
        printf("CHILD: exiting - will become zombie %d\n",getppid());
        sleep(20);
        exit(22);
    }
    else{
        //PARENT
        printf("PARENT: return pid %d\n", pid);
        printf("PARENT: pid: %5d  ppid: %5d\n", getpid(), getppid());
        printf("PARENT: sleeping forever...\n");
        sleep(10);
        exit(0);

        //while(1);
    }
}