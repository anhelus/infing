#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void caricaTemperature(int temperature[], int n) {
	srand(time(NULL));
	for (int i = 0; i <= n - 1; i++) {
		temperature[i] = rand() % 35 + 1;
		if (temperature[i] < 15 || temperature[i] > 25) {
			printf("Lettura %d: %d C - ATTENZIONE: Anomalia rilevata!\n", i + 1, temperature[i]); 
		} else {
			printf("Lettura %d: %d C - OK\n", i + 1, temperature[i]);
		}
	}
}

float calcoloMedia(int temperature[], int n) {
	int sommaTemp = 0;
	int temperatureValide = 0;
	for (int i = 0; i <= n - 1; i ++) {
		if (temperature[i] >= 15 && temperature[i] <= 25) {
			sommaTemp += temperature[i];
			temperatureValide += 1;
		}
	}
	return (float) sommaTemp / temperatureValide;
}

float calcolaPercentualeErrori(int temperature[], int n) {
	int temperatureValide = 0;
	for (int i = 0; i <= n - 1; i++) {
		if (temperature[i] >= 15 && temperature[i] <=25) {
			temperatureValide += 1;
		}
	}
	return (float) (n - temperatureValide) / n;
}

int main() {
	// Usiamo 10 come placeholder
	int n = 10;
	int temperature[n];
	caricaTemperature(temperature, n);
	
	// Calcoliamo la media
	float media = calcoloMedia(temperature, n);
	
	// Calcoliamo la percentuale di errori
	float percentualeErrori = calcolaPercentualeErrori(temperature, n);
    
    // 1. Esportazione su file libretto.txt
    FILE *fp = fopen("sensore.txt", "w");
    if (fp == NULL) {
        printf("Errore nell'apertura del file!\n");
        return 1;
    }
    
    fprintf(fp, "REPORT TEMPERATURE\n");
    fprintf(fp, "Temperatura media: %0.f C\n", media);
    fprintf(fp, "Percentuale letture errate: %0.f %%\n", percentualeErrori * 100);
    fclose(fp);

    return 0;
}
