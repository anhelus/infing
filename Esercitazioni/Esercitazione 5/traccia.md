### Traccia
Un'azienda agricola gestisce un certo numero di silos di grano, ognuno dei quali ha una certa capacità massima, assieme ad un livello di riempimento attuale. Creare un programma che identifichi quali silos necessitano di rifornimento urgente, implementando una logica di *allerta* per i silos che scendono al di sotto di una certa soglia critica.
#### Esercizio 1 - Diagramma di flusso
Definire un diagramma di flusso che permetta di implementare detta logica di allerta.
#### Esercizio 2 - Linguaggio C
Si implementi, mediante linguaggio C, una soluzione opportuna, salvando sul file `silos.txt` l'elenco dei silos critici, assieme alla quantità di grano da ordinare.
### Soluzione
I punti da considerare per la risoluzione di questa traccia sono i seguenti.
1. Generare in maniera casuale $N$ valori, ciascuno relativo ad un dato silos.
2. Ognuno dei valori sarà compreso tra $0$ (silos vuoto) e $100$ (silos pieno).
3. Iterare sul vettore di $N$ valori alla ricerca di tutti i valori al di sotto di una certa soglia $t$, che possiamo porre pari a $25$.
#### Esercizio 1
Una possibile logica per il diagramma di flusso è la seguente.
##### Funzione principale
- Dichiara un numero $N$ (numero silos).
- Dichiara un vettore `Riempimento[N]`.
- Chiama la funzione `caricaRiempimento(Riempimento, N)`.
- Chiama la funzione `lanciaAlert(Riempimento, N)`.

In particolare, la funzione `lanciaAlert` darà un feedback a schermo un messaggio relativo ad un riempimento sotto soglia del silos.

#### Esercizio 2
Anche in questo caso è in pratica richiesto il porting diretto da C del diagramma Flowgorithm. Procediamo quindi a definire la funzione `carica_riempimento`.

```c
void caricaRiempimento(int riempimento[], int n) {
	for (int i = 0; i <= n - 1; i++) {
		riempimento[i] = rand() % 101;
	}
}
```
A questo punto possiamo implementare la funzione `lanciaAlert`, che dovrà scrivere su file.
```c
void lanciaAlert(int riempimento[], int n) {
	FILE *fp = fopen("silos.txt", "w");
	if (fp == NULL) {
		printf("Errore nell'apertura del file!\n");
		return;
	}
	
	for (int i = 0; i <= n - 1; i++) {
		if (riempimento[i] < 25) {
			int daOrdinare = 100 - riempimento[i];
			fprintf(fp, "Allerta per il silos %d: riempimento al %d%%. Ordinare %d.\n", i+1, riempimento[i], daOrdinare);
			printf("Allerta: silos %d sotto la soglia critica\n", i + 1);
		}
	}
	fclose(fp);
}
```

Il main sarà quindi il seguente:

```c
int main() {
	srand(time(NULL));
	int n = 5;
	int riempimento[n];
	caricaRiempimento(riempimento, n);
	lanciaAlert(riempimento, n);
	return 0;
}
```

