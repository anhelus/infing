### Traccia
Durante le qualifiche di un Gran Premio, vengono registrati i tempi sul giro di tutti i piloti, espressi in secondi e millisecondi. Si crei un software che determini il tempo della Pole Position e calcoli, per ognuno degli altri piloti, il distacco temporale dal primo.
#### Esercizio 1 - Diagramma di flusso
Definire un apposito diagramma di flusso per mostrare a schermo i diversi tempi opportunamente ordinati.
#### Esercizio 2 - Programmazione C
Definire un programma C che sia in grado di mostrare la classifica e salvare i distacchi su un file `qualifiche.txt`.

### Soluzione

In questo caso è opportuno articolare la soluzione nei seguenti step.

1. Generare in maniera casuale $N$ valori. Questi dovranno avere una parte intera (compresa ad esempio  tra $0$ e $100$), rappresentativa dei secondi, ed  una decimale (compresa tra $0$ e $1000$), rappresentativa dei millisecondi.
2. Per calcolare il distacco, andrà ordinato il vettore dei tempi, e calcolata la differenza tra ciascun pilota ed il primo classification.

#### Esercizio 1

In questo caso, la generazione del vettore dei tempi può avvenire in diversi modi. Quello più semplice è probabilmente generare un numero casuale compreso tra 0 e 100*1000, e dividere poi per 1000, ottenendo un valore decimale rappresentativo di tempi che vanno da 0.0 a 99.999 secondi. Ovviamente, agendo sul numeratore della divisione (ed impostando ad esempio `random(M*1000)`) avremo tempi compresi tra 0 ed $(M-1).999$ secondi. La restante parte dell'implementazione è banale e demandata al lettore.

#### Esercizio 2

Anche in questo caso, la risoluzione è banale, e prevede un ordinamento del vettore, oltre che il calcolo delle differenze, che non sono salvate per ovvi motivi in un vettore apposito. Da sottolineare come, nell'esempio proposto, il vettore generato sia *hardcoded*; tuttavia, per generarlo in maniera casuale, basta seguire una logica analoga a quella utilizzata con l'Esercizio 1.

```c
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
```