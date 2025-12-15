#include <stdio.h>

void mostra_puntatore_intero(int* ptr) {
    printf("L'indirizzo del puntatore a intero e': %p\n", ptr);
}

void mostra_puntatore_decimale(double* ptr) {
    printf("L'indirizzo del puntatore a double e': %p\n", ptr);
}

int main() {
    int var_int = 10;
    double var_double = 20.5;
    mostra_puntatore_intero(&var_int);
    mostra_puntatore_decimale(&var_double);
    return 0;
}