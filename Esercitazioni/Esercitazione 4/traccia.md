### Traccia
Un sensore installato in un supermercato rileva le temperature a intervalli regolari di $15$ minuti. Tuttavia, dopo $N$ misurazioni, un operatore si accorge della presenza di valori *fuori scala*, che evidenziano che il sensore è difettoso. Si crei un programma che calcoli la media dei valori *in scala*, calcolando inoltre la percentuale di incidenza dei valori fuori scala rispetto al computo totale.
##### Esercizio 1 - Diagramma di flusso
Definire, mediante Flowgorithm, un opportuno diagramma di flusso che simuli la lettura di $N$ misurazioni. Si implementi inoltre una funzione di *anomaly detection* che notifichi a schermo l'utente in caso di lettura presumibilmente errata.
##### Esercizio 2 - Programmazione
Si implementi l'intero flusso di lavoro precedentemente illustrato, salvando in un file `sensore.txt` le informazioni riguardanti la media dei valori in scala e quelle relative alla percentuale di incidenza dei valori fuori scala, usando la seguente formattazione:

**REPORT TEMPERATURE**
**Temperatura media: 19 C**
**Percentuale letture errate: 24%**

N.B. Dato che le misure saranno generate casualmente, è *necessario generalizzare in maniera opportuna*.

### Soluzione
Questa traccia presenta qualche complessità in più delle precedenti, ma soltanto dal punto di vista *interpretativo*. Infatti, dovremo porre attenzione al seguenti aspetti. Infatti, la traccia non ci dice quali sono i valori da considerare *fuori scala*, ma parla soltanto di un generico *supermercato*. Tuttavia, possiamo assumere che in un supermercato i dipendenti ed i clienti non debbano stare né troppo freddi, né troppo caldi, per cui possiamo *supporre* che la temperatura debba essere compresa tra 15 e 25 gradi centigradi. Ovviamente, questa è una scelta del programmatore!
Una volta compreso questo dettaglio, il resto della traccia è banale. Dovremo infatti:
1. Generare in maniera casuale $N$ numeri, magari compresi tra $0$ e $100$.
2. Verificare quali sono al di fuori del range, e non considerarli nella media.
3. Contare quali sono al di fuori del range e calcolare l'incidenza totale.
Possiamo quindi considerare una soluzione di questo tipo.

#### Esercizio 1
Una possibile logica per il diagramma di flusso è la seguente.
##### Funzione principale
- Dichiara un Intero $N$ (numero letture).
- Dichiara un vettore `Temperature[N]`.
- Chiama la funzione `caricaTemperature(Temperature, N)`.
- Chiama la funzione `calcolaMedia(Temperature, N)`.
- Chiama la funzione `calcolaPercentualeErrori(Temperature, N)`.
#### Esercizio 2
In questo caso, è richiesto il porting diretto da C del diagramma fatto in Flowgorithm, oltre al salvataggio delle statistiche su un file di testo. Procediamo quindi a definire la funzione `calcolaMedia`.
```c
int calcoloMedia(int temperature[], int n) {
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
```
Procediamo adesso ad implementare la funzione `calcolaPercentualeErrori`.
```c
int calcolaPercentualeErrori(int temperature[], int n) {
	int temperatureValide = 0;
	for (int i = 0; i <= n - 1; i++) {
		if (temperature[i] >= 15 && temperature[i] <=25) {
			temperatureValide += 1;
		}
	}
	return (float) (n - temperatureValide) / n;
}
```
Possiamo quindi implementare il nostro `main` come segue.
```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void caricaTemperature(int temperature[], int n) {
	srand(time(NULL));
	for (int i = 0; i <= n - 1; i++) {
		temperature[i] = rand() % 50 + 1;
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
```