#include <stdio.h>

void ordina_esami(int libretto[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (libretto[j] < libretto[min_idx])
                min_idx = j;
        }
        int tmp = libretto[min_idx];
        libretto[min_idx] = libretto[i];
        libretto[i] = tmp;
    }
}

double calcolo_media(int libretto[], int n) {
    double somma = 0;
    // Partiamo dall'indice 2 per saltare i due minimi dopo l'ordinamento
    for (int i = 2; i < n; i++) {
        somma += libretto[i];
    }
    return somma / (n - 2);
}

double calcolo_voto_laurea(double mediaPesata) {
    return (mediaPesata * 110.0) / 30.0;
}

int main() {
    int libretto[7] = {23, 26, 28, 21, 22, 18, 18};
    int n = sizeof(libretto) / sizeof(libretto[0]);
    
    // 1. Esportazione su file libretto.txt
    FILE *fp = fopen("libretto.txt", "w");
    if (fp == NULL) {
        printf("Errore nell'apertura del file!\n");
        return 1;
    }

    fprintf(fp, "Carriera\n");
    for (int i = 0; i < n; i++) {
	    fprintf(fp, "Materia %d:\t%d\n", i+1, libretto[i]);
    }

    // 2. Ordinamento esami
    ordina_esami(libretto, n);

    // 3. Calcolo voto laurea
    double mediaPesata = calcolo_media(libretto, n);
    double votoLaurea = calcolo_voto_laurea(mediaPesata);

	// 4. Termine stampa
    fprintf(fp, "Media: \t\t%.0f\n", mediaPesata);
    fprintf(fp, "Voto di laurea: \t%.0f\n", votoLaurea);

    fclose(fp);

    return 0;
}
