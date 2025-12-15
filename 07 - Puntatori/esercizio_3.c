#include <stdio.h>

int* restituisci_puntatore(int* ptr_in) {
    printf("La funzione ha ricevuto il puntatore %p.\n", ptr_in);
    return ptr_in;
}

int main() {
    int var_int = 10;

    int* puntatore_originale = &var_int;
    printf("Puntatore originale: %p\n", (void*)puntatore_originale);
    int* puntatore_restituito = restituisci_puntatore(puntatore_originale);
    printf("Puntatore restituito: %p\n", (void*)puntatore_restituito);
    if (puntatore_originale == puntatore_restituito) {
        printf("I due puntatori sono identici.\n");
    } else {
        printf("I due puntatori sono differenti!\n");
    }

    return 0;
}