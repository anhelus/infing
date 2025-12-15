#include <stdio.h>

// Funzione con passaggio per valore
void incrementa_per_valore(int x) {
    printf("[INCREMENTA PER VALORE] - Il valore di x è %d\n", x);
    x++;
    printf("[INCREMENTA PER VALORE] - Il valore incrementato è %d\n", x);
}

// Funzione con passaggio per riferimento
void incrementa_per_riferimento(int* ptr_x) {
    printf("[INCREMENTA PER RIFERIMENTO] - Il valore di x è %d\n", *ptr_x);
    // Dereferenziamo il puntatore e incrementiamo il valore puntato.
    (*ptr_x)++;    
    printf("[INCREMENTA PER RIFERIMENTO] - Il valore incrementato è: %d\n", *ptr_x);
}


int main() {
    int x = 10;
    // 1. Passaggio per valore
    printf("Passaggio per valore\nIl valore di x prima della chiamata è: %d\n", x);
    incrementa_per_valore(x);
    printf("Il valore di x dopo la chiamata è: %d\n", x);
    // 2. Passaggio per riferimento
    printf("Passaggio per riferimento\nIl valore di x prima della chiamata è: %d\n", x);
    incrementa_per_riferimento(&x);
    printf("Il valore di x dopo la chiamata è: %d\n", x);
    return 0;
}