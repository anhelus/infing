#include <stdio.h>

int main() {
    int V[] = { 20, 15, 3, 2, 5 };

    for(int i = 1; i < 5; i++) {
        int j = i - 1;
        int tmp = V[i];
        while (j >= 0 && V[j] > tmp) {
            V[j+1] = V[j];
            j--;
        }
        V[j+1] = tmp;
    }

    printf("[");
    for(int i = 0; i < 4; i++) {
        printf("%d, ", V[i]);
    }
    printf("%d]", V[4]);

    return 0;
}