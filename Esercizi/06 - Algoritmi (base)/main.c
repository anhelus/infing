#include <stdio.h>
#include <stdbool.h>

int main() {
    int V[] = { 20, 15, 3, 2, 5 };
    int D = 16;
    bool trovato = false;
    for (int i = 0; i < 5; i++) {
        if (V[i] == D) {
            trovato = true;
        }
    }
    
    if (!trovato) {
        printf("Non ho trovato l'elemento!");
    }


    // Selection sort
    // for (int i = 0; i < 5; i++) {
    //     int k = i;
    //     for (int j = i + 1; j < 5; j++) {
    //         if (V[j] < V[k]) {
    //             k = j;
    //         }
    //     }
    //     int tmp = V[k];
    //     V[k] = V[i];
    //     V[i] = tmp;
    // }

    // Bubble sort
    // for (int i = 1; i < 5; i++) {
    //     for (int j = 4; j >= i; j--) {
    //         if (V[j] < V[j-1]) {
    //             int tmp = V[j];
    //             V[j] = V[j-1];
    //             V[j-1] = tmp;
    //         }
    //     }
    // }

    // Insertion sort
    // for (int i = 1; i < 5; i++) {
    //     int j = i - 1;
    //     int tmp = V[i];
    //     while (j >= 0 && V[j] > tmp) {
    //         V[j+1] = V[j];
    //         j--;
    //     }
    //     V[j+1] = tmp;
    // }

    // Stampa a schermo
    // printf("[");
    // for (int i = 0; i < 4; i++) {
    //     printf("%d, ", V[i]);
    // }
    // printf("%d]", V[4]);
}