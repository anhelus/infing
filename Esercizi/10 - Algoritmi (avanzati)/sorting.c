#include "sorting.h"

/*
 * Procedura che accetta un vettore in ingresso,
 * assieme alla sua dimensione, ed effettua un ordinamento
 * mediante selection sort.
*/
void selection_sort(int* V, int size) {
    for(int i = 0; i < size; i++) {
        int k = i;
        for(int j = i + 1; j < size; j++) {
            if (V[j] < V[k]) {
                k = j;
            }
        }
        int tmp = V[k];
        V[k] = V[i];
        V[i] = tmp;
    }
}

/*
 * Procedura che accetta un vettore in ingresso,
 * assieme alla sua dimensione, ed effettua un ordinamento
 * mediante bubble sort.
*/
void bubble_sort(int* V, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = (size-1); j > i; j--) {
            if(V[j] < V[j-1]) {
                int tmp = V[j];
                V[j] = V[j-1];
                V[j-1] = tmp;
            }
        }
    }
}

/*
 * Procedura che accetta un vettore in ingresso,
 * assieme alla sua dimensione, ed effettua un ordinamento
 * mediante insertion sort.
*/
void insertion_sort(int* V, int size) {
    for(int i = 1; i < size; i++) {
        int j = i - 1;
        int tmp = V[i];
        while (j >= 0 && V[j] > tmp) {
            V[j+1] = V[j];
            j--;
        }
        V[j+1] = tmp;
    }   
}