#include<stdio.h>

// 只需包含汇总的头文件，无需逐个包含子头文件
#include "libarith.h"

int main(){
	 
  int a = 10;
  int b = 20;
  int c = 100;

  int x = add(a, b);
  int y = sub(a, b);
  int z = inc(c);
  printf("add: %d   sub: %d   inc: %d\n", x, y, z);
  return 0;
}

// con gcc -c file.c   --> crea file.o
// poi gcc file.o -o nome  --> Crea file eseguibile usando ./nome

//possiamo anche saltare il passaggio di creare file.o e unire le funzioni direttamente in un libreria
//ar -r libarith.a file.o nome.o ... --> passa le cose del file.o in quello .a
//possiamo ora far eseguire il programma con: gcc main.o libarith.a -o myprog

//tutto in ordine:
//gcc -c *.c
//ar -r libarith.a add.o sub.o
//ranlib libarith.a
//gcc main.o libarith.a -o myprog