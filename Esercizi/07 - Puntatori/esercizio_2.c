#include <stdio.h>

void deferenzia_compara_intero(int val, int* ptr) {
    printf("L'indirizzo di memoria di val è: %p\n", &val);
    printf("Confronto il valore %d con il valore puntato da %p...\n", val, ptr);
    if (ptr != NULL && val == *ptr) {
        printf("Corrispondenza trovata! Valore dereferenziato: %d\n", *ptr);
    }
    printf("Errore: il puntatore e' nullo o il valore non corrisponde.\n");
}

int main() {
    int var_int = 10;
    double var_double = 20.5;

    deferenzia_compara_intero(var_int, &var_int); // Successo
    int altra_var_int = 99;
    deferenzia_compara_intero(var_int, &altra_var_int); // Fallimento

    return 0;
}