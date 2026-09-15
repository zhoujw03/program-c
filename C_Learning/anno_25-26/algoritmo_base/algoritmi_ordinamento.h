#ifndef ALGORITMO_ORDINAMENTO_H
#define ALGORITMO_ORDINAMENTO_H

void stampa_array(int arr[], int n);
void swap(int *a, int *b);

void insertionSort(int arr[], int n);

void merge_sort(int arr[], int left, int right);
void merge(int arr[], int left, int mean, int right);

void heap_sort(int arr[], int dimensione);
void max_heaify(int arr[], int dimensione, int i);

#endif