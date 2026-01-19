#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int voto;
} Esame;

void ordina_esami(Esame libretto[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (libretto[j].voto < libretto[min_idx].voto)
                min_idx = j;
        }
        Esame temp = libretto[min_idx];
        libretto[min_idx] = libretto[i];
        libretto[i] = temp;
    }
}

double calcolo_media(Esame libretto[], int n) {
    double somma = 0;
    for (int i = 2; i < n; i++) {
	    somma += libretto[i].voto;
	}
    return somma / (n - 2);
}

double calcolo_voto_laurea(double mediaPesata) {
    return (mediaPesata * 110.0) / 30.0;
}

int main() {
    int n = 7;
    Esame libretto[7];
    
    char *nomi_test[] = {"Materia 1", "Materia 2", "Materia 3", "Materia 4", "Materia 5", "Materia 6", "Materia 7"};
    int voti_test[] = {23, 26, 28, 21, 22, 18, 18};

    for (int i = 0; i < n; i++) {
        strcpy(libretto[i].nome, nomi_test[i]);
        libretto[i].voto = voti_test[i];
    }

    ordina_esami(libretto, n);

    double mediaPesata = calcolo_media(libretto, n);
    double votoLaurea = calcolo_voto_laurea(mediaPesata);

    // 4. Esportazione su file libretto.txt
    FILE *fp = fopen("libretto.txt", "w");
    if (fp == NULL) {
        printf("Errore nell'apertura del file!\n");
        return 1;
    }

    fprintf(fp, "Carriera\n");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%s:\t%d\n", nomi_test[i], voti_test[i]);
    }

    fprintf(fp, "Media: \t\t%.0f\n", mediaPesata);
    fprintf(fp, "Voto di laurea: \t%.0f\n", votoLaurea);

    fclose(fp);

    return 0;
}