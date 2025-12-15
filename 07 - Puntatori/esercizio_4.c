#include <stdio.h>

void puntatore_a_void(char c) {
    printf("Ricevuto il carattere '%c'.\n", c);
    void* generic_ptr = &c;
    printf("L'indirizzo memorizzato nel puntatore a void e': %p\n", generic_ptr);
    // Cast a puntatore del tipo corretto
    char* char_ptr = (char*)generic_ptr;
    printf("Dopo il cast, il valore dereferenziato e': '%c'\n", *char_ptr);
}

int main() {
    puntatore_a_void('Z');
    return 0;
}