#include <stdio.h>

/*
 * Funzione che dereferenzia un puntatore ad intero e verifica
 * che sia uguale al valore puntato.
 */
void deferenzia_compara_intero(int val, int* ptr) {
    printf("L'indirizzo di memoria di val è: %p\n", &val);
    printf("Confronto il valore %d con il valore puntato da %p...\n", val, ptr);
    // Controlliamo che il puntatore non sia NULL!
    if (ptr != NULL && val == *ptr) {
        printf("Corrispondenza trovata! Valore dereferenziato: %d\n", *ptr);
    }
    printf("Errore: il puntatore e' nullo o il valore non corrisponde.\n");
}

int main() {
    int var_int = 10;
    double var_double = 20.5;

    deferenzia_compara_intero(var_int, &var_int);
    int altra_var_int = 99;
    deferenzia_compara_intero(var_int, &altra_var_int);

    return 0;
}