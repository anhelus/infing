#include <stdio.h>

int incrementa() {
    int contatore = 0;
    return ++contatore;
}

int main() {
    printf("Il valore del contatore è %d\n", incrementa()); // Stamperà  1
    printf("Il valore del contatore è %d\n", incrementa()); // Stamperà sempre 1!
    return 0;
}