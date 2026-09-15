all: myprog

myprog: test.o libarith.a
		gcc test.o libarith.a -o $@

# nuovi funzione ricorda di inserire qui
libarith.a: funzione/insertionSort.o funzione/stampa_array.o funzione/MergeSort.o	\
			funzione/HeapSort.o
		ar -r $@ $^
		ranlib $@

test.o: test.c algoritmi_ordinamento.h
		gcc -c $< -o $@

# qui
funzione/insertionSort.o: funzione/insertionSort.c
		gcc -c $< -o $@
funzione/MergeSort.o: funzione/MergeSort.c
		gcc -c $< -o $@
funzione/HeapSort.o: funzione/HeapSort.c
		gcc -c $< -o $@


funzione/stampa_array.o: funzione/stampa_array.c
		gcc -c $< -o $@

clean:
	rm -f myprog libarith.a *.o funzione/*.o

# e qui
test.o: test.c algoritmi_ordinamento.h
funzione/insertionSort.o: funzione/insertionSort.c
funzione/stampa_array.o: funzione/stampa_array.c
funzione/MergeSort.o: funzione/MergeSort.c
funzione/HeapSort.o: funzione/HeapSort.c
