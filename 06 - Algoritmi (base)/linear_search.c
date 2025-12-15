#include <stdio.h>
#include <stdbool.h>

int main() {
    int V[5] = { 20, 13, 5, 3, 2 };
    int key = 13;
    bool found = false;

    for(int i = 0; i < 5; i++) {
        if(V[i] == key)
            found = true;
    }
    if(found) {
        printf("Sono il Mastro di Chiavi! La chiave %d è presente!", key);
    } else {
        printf("Sono il Mastro di Chiavi! La chiave %d non è presente!", key);
    }

    return 0;
}