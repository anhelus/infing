#include <stdio.h>
#include <stdlib.h>

void ordina_classifica(float tempi[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (tempi[j] < tempi[min_idx]) {
                min_idx = j;
            }
        }
        float temp = tempi[min_idx];
        tempi[min_idx] = tempi[i];
        tempi[i] = temp;
    }
}

void salva_distacchi(float tempi[], int n) {
    FILE *fp = fopen("qualifiche.txt", "w");
    if (fp == NULL) {
        printf("Errore nell'apertura del file!\n");
        return;
    }

    float poleTime = tempi[0]; // Il primo dopo l'ordinamento è la Pole
    fprintf(fp, "REPORT DISTACCHI (Pole Position: %.3f s)\n", poleTime);

    for (int i = 1; i < n; i++) {
        float distacco = tempi[i] - poleTime;
        fprintf(fp, "Pilota %d: +%.3f s\n", i + 1, distacco);
    }

    fclose(fp);
}

int main() {
    int n = 6;
    float tempi[] = {84.520, 83.110, 85.005, 83.450, 86.120, 84.000};
    ordina_classifica(tempi, n);
    salva_distacchi(tempi, n);
    return 0;
}