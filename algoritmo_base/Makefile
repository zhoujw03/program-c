all: myprog

myprog: test.o libarith.a
		gcc test.o libarith.a -o $@

libarith.a: funzione/insertionSort.o funzione/printArray.o
		ar -r $@ $^
		ranlib $@

test.o: test.c algoritmi_ordinamento.h
		gcc -c $< -o $@

funzione/insertionSort.o: funzione/insertionSort.c
		gcc -c $< -o $@

funzione/printArray.o: funzione/printArray.c
		gcc -c $< -o $@

clean:
	rm -f myprog libarith.a *.o funzione/*.o


test.o: test.c algoritmi_ordinamento.h
funzione/insertionSort.o: funzione/insertionSort.c
funzione/printArray.o: funzione/printArray.c

