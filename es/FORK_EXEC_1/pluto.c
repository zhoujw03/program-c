#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char **argv){

    char *p;
    int num = strtol(argv[1], &p, 10);
    
    printf("PLUTO-ARGC: %d\n", argc);

    for (int i = 0; i < argc; i++ ){
        printf("PLUTO-ARGV[%d]: %s\n", i, argv[i]);
    }
    exit(45);
}