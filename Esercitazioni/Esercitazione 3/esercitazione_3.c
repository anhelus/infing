#include <stdio.h>
#include <stdlib.h>

int somma_conto(int prezzi[], int n) {
    int totale = 0;
    for (int i = 0; i < n; i++) {
        totale += prezzi[i];
    }
    return totale;
}

void genera_conto(int numPietanze, int numAmici, int prezzi[], double quota) {
    FILE *f = fopen("conto.txt", "w");
    if (f == NULL) {
        printf("Errore nella creazione del file!\n");
        return;
    }

    fprintf(f, "Consumazione\n");
    for (int i = 0; i < numPietanze; i++) {
        fprintf(f, "Pietanza %d\t%d €\n", i + 1, prezzi[i]);
    }
    fprintf(f, "A testa:\t%.2f €\n", quota);

    fclose(f);
}

int main() {
    int numAmici = 3;
    int numPietanze = 6;
    int prezzi[] = {15, 12, 8, 6, 2, 3};

    int totale = somma_conto(prezzi, numPietanze);
    double quotaIndividuale = (double) totale / numAmici;

    genera_conto(numPietanze, numAmici, prezzi, quotaIndividuale);

    return 0;
}
