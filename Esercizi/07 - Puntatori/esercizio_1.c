#include <stdio.h>

// Funzione che mostra il puntatore ad intero
void mostra_puntatore_intero(int* ptr) {
    printf("L'indirizzo del puntatore a intero e': %p\n", ptr);
    printf("Il valore puntato è: %d\n", *ptr);
}

// Funzione che mostra il puntatore a decimale
void mostra_puntatore_decimale(double* ptr) {
    printf("L'indirizzo del puntatore a double e': %p\n", ptr);
    printf("Il valore puntato è: %.2f\n", *ptr);
}

int main() {
    int var_int = 10;
    double var_double = 20.5;
    int* punt_var_int = &var_int;
    mostra_puntatore_intero(punt_var_int);
    mostra_puntatore_decimale(&var_double);
    return 0;
}