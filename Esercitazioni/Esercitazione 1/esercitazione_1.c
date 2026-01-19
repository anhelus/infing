#include <stdio.h>
#include <stdbool.h>

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

bool linear_search(int* V, int size, int k) {
    for(int i = 0; i < size; i++) {
        if(V[i] == k)
            return true;
    }
    return false;
}

int main() {
	int S[] = {12, 33, 21, 42, 5};
	int S_size = sizeof(S) / sizeof(S[0]);
	// 1: Ordinamento del vettore
	selection_sort(S, S_size);
	// 2: Individuazione di minimo e massimo nel vettore
	printf("Minimo: %d\n", S[0]);
	printf("Massimo: %d\n", S[S_size-1]);
	// 3: Ricerca valore k
	int k;
	printf("Inserire il valore da cercare nel vettore: ");
	scanf("%d", &k);
	if(linear_search(S, S_size, k)) {
		printf("Il valore %d e' presente nel vettore.\n", k);
	} else {
		printf("Il valore %d non e' presente nel vettore.\n", k);
	}	
	return 0;
}