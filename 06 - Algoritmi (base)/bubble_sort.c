#include <stdio.h>

int main() {
    int V[5] = { 20, 13, 5, 3, 2 };

    for(int i = 0; i < 5; i++) {
        for(int j = 4; j > i; j--) {
            if(V[j] < V[j-1]) {
                int tmp = V[j];
                V[j] = V[j-1];
                V[j-1] = tmp;
            }
        }
    }

    printf("[");
    for(int i = 0; i < 4; i++) {
        printf("%d, ", V[i]);
    }
    printf("%d]", V[4]);

    return 0;
}