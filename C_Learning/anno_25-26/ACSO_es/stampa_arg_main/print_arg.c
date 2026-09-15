#include<stdio.h>

int main( int argc, char* argv[]){
  printf("number of args: %d\n",argc);
  printf("Program name: %s\n", argv[0]);
  
  for(int n = 1; n < argc; n++){
    printf("Arg %d: %s\n",n, argv[n]);
  }

  return 0;
}
