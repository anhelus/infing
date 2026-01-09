#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void caricaRiempimento(int riempimento[], int n) {
	for (int i = 0; i <= n - 1; i++) {
		riempimento[i] = rand() % 101;
	}
}

void lanciaAlert(int riempimento[], int n) {
	FILE *fp = fopen("silos.txt", "w");
	if (fp == NULL) {
		printf("Errore nell'apertura del file!\n");
		return;
	}
	
	for (int i = 0; i <= n - 1; i++) {
		if (riempimento[i] < 25) {
			int daOrdinare = 100 - riempimento[i];
			fprintf(fp, "Allerta per il silos %d: riempimento al %d%%. Ordinare %d%% del riempimento.\n", i+1, riempimento[i], daOrdinare);
			printf("Allerta: silos %d sotto la soglia critica\n", i + 1);
		}
	}
	fclose(fp);
}

int main() {
	srand(time(NULL));
	int n = 50;
	int riempimento[n];
	caricaRiempimento(riempimento, n);
	lanciaAlert(riempimento, n);
	return 0;
}
