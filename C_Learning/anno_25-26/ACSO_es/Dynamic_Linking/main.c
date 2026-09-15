//prima di iniziare si deve costruire una libreria dinamica che termina con .so 
//li dobbiamo dire che vogliamo creare una libreria dinamica 
//e i comandi sono: gcc -c -shared add.c 
//nel Mac si deve usare: gcc -c -fPIC add.c

//dove crea un add.o con infomazioni per creare libreria dinamica, poi la stessa cosa con sub.c
//a questo punto costruiamo la libreria dinamica con questo comando: 
// gcc -shared add.o sub.o -o libarith.so

// cosi facendo non c'e piu' bisogno di linkare con main ma viene caricato direttamente a runtime

#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>   //deve includere questo per usare la libreria dinamica
#include<math.h>

// definisco un typedef chiamato add_ptr_t, che e' un "puntatore a funzione" e prende due argomenti come ingresso
//  e ritorna un intero, idem per la funzione sub
typedef int (*add_ptr_t)(int, int);
typedef int (*sub_ptr_t)(int, int);

#include "libarith.h"

int main(){
	 
  int a = 10;
  int b = 20;

  // dichiaro un puntatore a void
  void *handler;

  // poi dichiaro due variabili che sono add_ptr e sub_ptr, che e' un puntatore di tipo add_ptr_t e sub_ptr_t;
  // dove uno punta al funzione add e l'altro al funzione sub
  add_ptr_t add_ptr;
  sub_ptr_t sub_ptr;

  float *pi_ptr; // puntatore di tipo float
  float pi;      // variabile di tipo float

 // per aprire la libreria dinamica utilizzo la funzione dlopen dove passo il nome della libreria con davanti ./ che significa nella directory corrente
  handler = dlopen("./libarith.so", RTLD_LAZY);    //RTLD_LAZY per usi minimi, mentre RTLD_NOW carica tutta la libreria in memoria

  // se handler e' nullo, dimmi quale e' errore utilizzando la funzione dlerrer() e ritorna ultimo operazione
  if (handler == NULL)
  {
    printf("dlopen: %s\n", dlerror());
    exit(1);    //medoto standard per uscire con un errore
  }

  // con la funzione dlsym: cerco la funzione add nella libreria in cui si riferisce handler, se tutto va bene ritorna la funzione add
  // sotto forma di void*, e lo converto in add_ptr_t e infine lo assegno a add_ptr
  add_ptr = (add_ptr_t)dlsym(handler, "add");
  if (add_ptr == NULL){
    printf("dlsym(add): %s\n", dlerror());    //la stessa cosa di sopra, se e' nullo stampo errore
    exit(1);
  }

  //sub
  sub_ptr = (sub_ptr_t)dlsym(handler, "sub");
  if (sub_ptr == NULL){
    printf("dlsym(sub): %s\n", dlerror());
    exit(1);
  }

// Attenzione: qui deve cercare il simbolo pi, ma il simbolo pi non e' una funzione ma una variabile
  pi_ptr = (float *)dlsym(handler, "pi");
  if (pi_ptr == NULL){
    printf("dlsym(pi): %s\n", dlerror());    
    exit(1);
  }

  //NON andare a cercare una variabile in questo modo, perche potrebbe dare tanto problema durante esecuzione
  //per esempio se non trova pi, ritorna NULL, ma puntatore a NULL restituisce valore 0
  
  // pi= *((float *)dlsym(handler, "pi"));

  // int z = add(a,b);
  int z = (*add_ptr)(a, b);
  printf("z: %d\n", z);

  // int w = sub (a, b);
  int w = (*sub_ptr)(a, b);
  printf("w: %d\n", w);

  // float s = sin(2 * pi / 3);
  float s = sin(2 * (*pi_ptr) / 3);
  printf("s: %f\n", s);

  // alla fine chiudo la libreria
  dlclose(handler);

  return 0;
}
