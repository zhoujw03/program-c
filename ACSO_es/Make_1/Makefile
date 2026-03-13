all: myprog

myprog: main.o libarith.a
		gcc main.o libarith.a -o $@

libarith.a: add.o sub.o
		ar -r $@ add.o sub.o
		ranlib $@

main.o: main.c
		gcc -c $< -o $@

add.o: add.c
		gcc -c $< -o $@

sub.o: sub.c
		gcc -c $< -o $@

clean:
	rm -f myprog libarith.a *.o

# puo usare comando: gcc -MM *.c >> Makefile
#per aggiungere quello che c'e sotto direttamente nel file Makefile
add.o: add.c add.h
main.o: main.c libarith.h add.h sub.h
sub.o: sub.c sub.h