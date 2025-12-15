#include <stdio.h>

int main() {
    int V[5] = { 20, 13, 5, 3, 2 };
    for(int i = 0; i < 5; i++) {
        int k = i;
        for(int j = i + 1; j < 5; j++) {
            if (V[j] < V[k]) {
                k = j;
            }
        }
        int tmp = V[k];
        V[k] = V[i];
        V[i] = tmp;
    }
    printf("[");
    for(int i = 0; i < 4; i++) {
        printf("%d, ", V[i]);
    }
    printf("%d]", V[4]);
    return 0;
}