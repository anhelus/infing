### Traccia
Un ponte autostradale è dotato di $N$  sensori di carico che registrano il peso dei mezzi in transito (in tonnellate). Si progetti un opportuno sistema di reportistica.
#### Esercizio 1 - Diagramma di flusso
Definire un apposito diagramma di flusso per mostrare a schermo i carichi passati sugli $N$  sensori.
#### Esercizio 2 - Programmazione C
Si definisca un programma in grado di ordinare i carichi dal più pesante al più leggero, generando c contestualmente un report che restituisce un messaggio di  allerta per ogni carico superiore ad un certo  limite consentito.
## Soluzione
#### Esercizio 2
```c
#include <stdio.h>
#include <stdlib.h>

void ordina_decrescente(float carichi[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
	        // E' un selection sort, ma con l'ordinamento invertito!
            if (carichi[j] > carichi[max_idx]) {
                max_idx = j;
            }
        }
        float temp = carichi[max_idx];
        carichi[max_idx] = carichi[i];
        carichi[i] = temp;
    }
}

void genera_report(float carichi[], int n, float limite) {
    FILE *fp = fopen("ponte.txt", "w");
    if (fp == NULL) {
        printf("Errore: impossibile creare il file di report.\n");
        return;
    }
    
    fprintf(fp, "REPORT STRESS STRUTTURALE PONTE\n");
    fprintf(fp, "Limite di sicurezza impostato: %.2f t\n", limite);

    int contatoreCritici = 0;
    for (int i = 0; i < n; i++) {
        fprintf(fp, "Mezzo %d: %.2f t", i + 1, carichi[i]);        
        if (carichi[i] > limite) {
            fprintf(fp, " [ATTENZIONE: OLTRE LIMITE]");
            contatoreCritici++;
        }
        fprintf(fp, "\n");
    }

    fprintf(fp, "Totale mezzi transitati: %d\n", n);
    fprintf(fp, "Totale mezzi oltre il limite: %d\n", contatoreCritici);

    fclose(fp);
}

int main() {
    int n = 8;
    float carichi[] = {12.5, 42.8, 7.2, 35.0, 48.6, 22.1, 5.5, 44.2};
    float limite;

    printf("Inserire il carico limite di sicurezza (t): ");
    scanf("%f", &limite);

    ordina_decrescente(carichi, n);
    genera_report(carichi, n, sogliaUtente);

    return 0;
}
```