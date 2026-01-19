#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imposta_angoli_possibili(int stati[]) {
    int k = 0; // Placeholder per indice vettore    
    // Il ciclo avanza direttamente con il passo di 45 gradi
    for (int i = 0; i <= 360; i = i + 45) {
        stati[k] = i;
        k++;
    }
}

void pianifica_movimenti(int stati[], int sceltiAndata[], int sceltiRitorno[], int n) {
    for (int i = 0; i < n; i++) {
        int r = rand() % 9; 
        sceltiAndata[i] = stati[r];
        sceltiRitorno[i] = -stati[r];
    }
}

void genera_report(int sceltiAndata[], int sceltiRitorno[], int n) {
    FILE *fp = fopen("robot.txt", "w");
    if (fp == NULL) return;

    fprintf(fp, "LOG MOVIMENTAZIONE BRACCIO ROBOTICO\n\n");

    for (int i = 0; i < n; i++) {
        fprintf(fp, "Movimento %d: Andata %d gradi | Ritorno %d gradi\n", i + 1, sceltiAndata[i], sceltiRitorno[i]);
    }
    fclose(fp);
}

int main() {
    srand(time(NULL));
    int n = 5; // Numero di movimenti da simulare
    
    int stati[9];  // 9 posizioni possibili (0, 45, 90... 360)
    int sceltiAndata[n]; // Vettore dei movimenti effettuati
    int sceltiRitorno[n];

    imposta_angoli_possibili(stati);

    // Fase 2: Esecuzione operativa (scelta casuale)
    pianifica_movimenti(stati, sceltiAndata, sceltiRitorno, n);

    // Fase 3: Analisi dati e salvataggio
    genera_report(sceltiAndata, sceltiRitorno, n);

    return 0;
}
