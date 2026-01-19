### Traccia
##### Esercizio 1 – Diagramma di flusso
Definire gli appositi diagrammi di flusso per soddisfare le seguenti richieste.
1.      Caricare due vettori di dimensione _N_. Verificare che tutti gli elementi del primo vettore siano pari, mentre quelli del secondo siano dispari. Il caricamento deve avvenire senza alcun input da parte dell'utente.
2.      Si individuino il minimo e il massimo del vettore risultante dalla somma, elemento per elemento, dei due vettori caricati al punto 1.
##### Esercizio 2 – Programmazione
Si consideri il vettore `S = {12, 33, 21, 42, 5}`.
1. Ordinare il vettore ottenuto in ordine crescente.
2. Replicare il risultato ottenuto al punto 2 dell'esercizio 1 senza utilizzare strutture di tipo iterativo.
3. Verificare che un certo valore `k` sia presente nel vettore definito al punto 1.
Si implementino le funzionalità esposte nella traccia in linguaggio C, secondo le opportune funzioni e procedure **_generalizzabili_**. Si tenga a mente l'interazione con l'utente, verificando la correttezza del programma.
#### Soluzione
#### Esercizio 1
Concentriamoci in primis sul diagramma di flusso, per poi passare ad implementare il programma in C.
Il punto 1 ci chiede di caricare due vettori, entrambi di dimensione *N*. Per farlo, è *fortemente consigliato* definire una funzione, che potremo chiamare `caricaVettore`, che ci permetterà di caricare un vettore *arbitrario*. Ovviamente, potremmo tranquillamente creare due diverse funzioni, o scrivere il tutto all'interno dello script principale; tuttavia, seppur funzionante, questa scelta andrebbe contro i principi della programmazione modulare, aumentando la ripetizione di codice ed il rischio di errori, per cui è da evitare.
Per creare la funzione `caricaVettore`, dovremo creare una nuova funzione in Flowgorithm. Come parametri, ricordiamo che il programma non ha una funzione nativa per determinare la lunghezza di un vettore, per cui dovremo passare il vettore `V` e la sua lunghezza `N`. La procedura di caricamento dovrà inoltre avere un flag per verificare che il valore caricato sia pari o dispari. Quest'ultimo aspetto, in particolare, presenta la necessità di definire una funzione booleana apposita per gestire l'inserimento dei numeri: dovremo inserire un numero pari quando il flag sarà a true, e un dispari quando il flag sarà a false. Ovviamente, per verificare che il numero inserito (o generato casualmente!) sia pari o dispari, dovremo valutare che il resto della divisione del numero per 2 sia pari a zero. Date quindi queste due condizioni (ovvero il valore della variable flag e quello di `V[i] % 2 == 0`) potremo stilare una tabella delle verità con la funzione attesa, come di seguito.

| `flag` | `V[i] % 2 == 0` | Risultato |
| ------ | --------------- | --------- |
| True   | True            | True      |
| True   | False           | False     |
| False  | True            | False     |
| False  | False           | True      |
Appare quindi evidente che il risultato sarà *true* quando `flag == (V[i] % 2 == 0)`, e `false` altrimenti. Inserendo questa condizione nella verifica di un ciclo dowhile, avremo a disposizione tutto ciò che serve per implementare la funzione desiderata.
La funzione di somma dei vettori sarà molto semplice, e dovrà accettare in ingresso tre vettori, ovvero i due precedentemente creati, più un terzo che farà da placeholder per la somma, e consisterà in un ciclo `for` che sommerà gli elementi uno ad uno fino al raggiungimento del risultato finale. In modo simile, sarà possibile implementare le funzioni per individuare il minimo ed il massimo del vettore.
#### Esercizio 2
Una volta ottenuto il vettore risultante dal punto 2, dovremo passare al secondo esercizio. In questo specifico caso, il vettore potrà essere codificato direttamente nel main, come segue.

```c
int main() {
	int S[] = {12, 33, 21, 42, 5};
	return 0;
}
```

Dovremo quindi implementare una funzione per l'ordinamento. Dato che la traccia non specifica alcun algoritmo, usiamo il selection sort:

```c
void selection_sort(int* V, int size) {
    for(int i = 0; i < size; i++) {
        int k = i;
        for(int j = i + 1; j < size; j++) {
            if (V[j] < V[k]) {
                k = j;
            }
        }
        int tmp = V[k];
        V[k] = V[i];
        V[i] = tmp;
    }
}
```

A questo punto, una volta ottenuto il vettore ordinato, potremo verificare che il massimo ed il minimo siano quelli estratti nell'esercizio precedente. Ovviamente, ciò non comporta la definizione di funzioni con cicli, in quanto il minimo ed il massimo saranno il primo e l'ultimo valore del vettore considerato, rispettivamente.

L'ultima parte prevede l'implementazione di una funzione di ricerca per individuare il valore k all'interno del vettore. Anche in questo caso, non è specificato l'algoritmo da utilizzare, per cui possiamo limitarci ad usare la ricerca lineare:

```c
#include <stdbool.h>

bool linear_search(int* V, int size, int k) {
    for(int i = 0; i < size; i++) {
        if(V[i] == k)
            return true;
    }
    return false;
}
```

Terminiamo inserendo il tutto all'interno del nostro `main`:
```c
#include <stdio.h>
#include <stdbool.h>

int main() {
	int S[] = {12, 33, 21, 42, 5};
	int S_size = sizeof(S) / sizeof(S[0]);
	// 1: Ordinamento del vettore
	selection_sort(S, S_size);
	// 2: Individuazione di minimo e massimo nel vettore
	printf("Minimo: %d\n", S[0]);
	printf("Massimo: %d\n", S[n-1]);
	// 3: Ricerca valore k
	int k;
	printf("Inserire il valore da cercare nel vettore: ");
	scanf("%d", &k);
	if(linear_search(S, S_size, k)) {
		printf("Il valore %d e' presente nel vettore.\n", k);
	} else {
		printf("Il valore %d non e' presente nel vettore.\n", k);
	}	
	return 0;
}
```