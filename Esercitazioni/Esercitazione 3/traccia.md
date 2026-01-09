### Traccia
Un gruppo di _N_ amici si reca al ristorante e, una volta terminato il pasto, decide di utilizzare il programma "_Sparticonto_", comunemente usato dai giovani d'oggi per dividere in parti eguali il conto.
##### Esercizio 1 – Diagramma di flusso
Definire, mediante Flowgorithm, un opportuno diagramma di flusso che consenta di caricare il costo di ogni singola pietanza o bevanda consumata. Si organizzi il programma in base alle funzioni e/o alle procedure pertinenti.
##### Esercizio 2 – Programmazione
Dato l'elenco dei costi delle pietanze caricate, si implementi la funzionalità di suddivisione del conto in C, utilizzando le opportune funzioni e procedure **_generalizzabili_**. Si testi la validità del programma creando un file di testo chiamato _conto.txt_, contenente le seguenti informazioni:
**Consumazione  
Pietanza 1 15 €  
Pietanza 2 12 €  
Pietanza 3 8 €  
Pietanza 4 6 €  
Pietanza 5 2 €  
Pietanza 6 3 €  
A testa:   15.33 €**
### Soluzione
Partiamo anche in questo caso dall'analisi del problema. Dovremo dividere un conto e, per farlo, avremo bisogno di:
1.  Conoscere il numero di amici ($N$).
2.  Acquisire i prezzi delle singole pietanze.
3.  Sommare i costi per ottenere il conto.
4.  Dividere il totale per $N$.
#### Esercizio 1
Partiamo dal primo esercizio; una possibile struttura è la seguente:
##### Funzione principale
- Definisci due interi `numAmici` e `numPietanze`, da leggere mediante input utente.
- Definisci un vettore `prezzi`. Questo deve essere caricato in maniera casuale. Verificare che i prezzi siano maggiori di zero mediante la funzione `caricaPietanze(prezzi, numPietanze)`.
##### Funzione `caricaPietanze`:
*   Ciclo `For i = 0 to numPietanze - 1`:
	* Generazione casuale `prezzi[i]`.
	* Verifica in un `dowhile`.
#### Esercizio 2
Nella soluzione C, utilizzeremo un array per i prezzi e, per rendere il programma simile all'output richiesto, un array di stringhe per i nomi delle pietanze.

```c
#include <stdio.h>
#include <stdlib.h>

int somma_conto(int prezzi[], int n) {
    int totale = 0;
    for (int i = 0; i < n; i++) {
        totale += prezzi[i];
    }
    return totale;
}

void genera_conto(int numPietanze, int numAmici, int prezzi[], double quota) {
    FILE *f = fopen("conto.txt", "w");
    if (f == NULL) {
        printf("Errore nella creazione del file!\n");
        return;
    }

    fprintf(f, "Consumazione\n");
    for (int i = 0; i < numPietanze; i++) {
        fprintf(f, "Pietanza %d\t%d €\n", i + 1, prezzi[i]);
    }
    fprintf(f, "A testa:\t%.2f €\n", quota);

    fclose(f);
}

int main() {
    int numAmici = 3;
    int numPietanze = 6;
    int prezzi[] = {15, 12, 8, 6, 2, 3};

    int totale = somma_conto(prezzi, numPietanze);
    double quotaIndividuale = (double) totale / numAmici;

    genera_conto(numPietanze, numAmici, prezzi, quotaIndividuale);

    return 0;
}
```
