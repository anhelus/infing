#include <stdio.h>

void compara_intervalli(int a, int b, int c, int d) {
    int max_estremo_inferiore = a;
    int min_estremo_superiore = b;
    if (c > a) {
        max_estremo_inferiore = c;
    }
    if (d < b) {
        min_estremo_superiore = d;
    }
    printf("Il maggiore tra gli elementi e' %d\n", max_estremo_inferiore);
    printf("Il minore tra gli elementi e' %d\n", min_estremo_superiore);
    // Ricordiamo che il numero di elementi nell’intervallo [a, b] è dato da b – a + 1!
    if ((b - a) != (d - c)) {
        printf("Gli intervalli non hanno lo stesso numero di elementi\n");
    } else {
        printf("Gli intervalli hanno lo stesso numero di elementi\n");
    }
}

int main() {
    compara_intervalli(2, 4, 5, 7);
}