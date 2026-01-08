### Traccia
Si richiede di progettare il programma _"Libretto"_. Questo programma dovrà consentire l'inserimento delle informazioni relative alla carriera dello studente, calcolare la media e il voto di laurea, nonché l'esportazione in file di testo dell'intera carriera dello studente. Si ricorda che, nel computo del voto di laurea, devono essere esclusi i due voti più bassi. Per semplicità, si considerino tutti gli esami equivalenti a un numero comune di CFU.
##### Esercizio 1 – Diagramma di flusso
Definire, mediante Flowgorithm, un opportuno diagramma di flusso che consenta di caricare un vettore di voti validi. Si mostrino quindi a schermo tutti i voti, tranne i due più bassi. Si organizzi il programma in base alle funzioni e/o alle procedure pertinenti, fornendo un feedback opportuno all'utente.
##### Esercizio 2 – Programmazione
Si implementino le funzionalità di calcolo del voto di laurea in linguaggio C, secondo le opportune funzioni e procedure **_generalizzabili_**. Si tenga a mente l'interazione con l'utente, verificando la correttezza del programma. Si testi inoltre la validità dello stesso creando un file di testo chiamato _libretto.txt_, contenente le seguenti informazioni:
**Carriera  
Materia 1       23  
Materia 2       26  
Materia 3       28  
Materia 4       21  
Materia 5       22  
Materia 6       18  
Materia 7       18  
Media:          24  
Voto di laurea: 88**

### Soluzione
In questo caso, è opportuno partire dall'analisi della traccia, che ci chiede di costruire un programma che sia in grado di gestire la carriera di uno studente e, di conseguenza, un insieme di voti. Dovremo porre particolare attenzione a tre aspetti:
1. Ogni voto dovrà essere compreso tra 18 e 30, per cui dovremo verificare la correttezza dello stesso.
2. Dovremo escludere i due voti più bassi.
3. Dovremo calcolare la media tenendo conto dei due esami esclusi.

Potremo quindi utilizzare un ciclo `do-while` per verificare la correttezza del voto, ordinare i voti escludendo i due più bassi, e calcolare la media considerando non `N` voti, bensì `N-2`.
#### Esercizio 1
Una possibile logica per il diagramma di flusso è la seguente.
##### Funzione principale
*   Dichiara un intero $N$ (numero esami).
*   Dichiara un vettore `Voti[N]`.
*   Chiama `caricaVoti(Voti, N)`.
*   Chiama `ordinaVoti(Voti, N)`.
*   Chiama `mostraVotiFiltrati(Voti, N)`.
##### Funzione `caricaVoti(Integer Array V, Integer N)`:
*   Ciclo `For i = 0 to N-1`:
	*   Ciclo `Do`: Input `V[i]` mentre `V[i] < 18` o `V[i] > 30`.
##### Funzione `ordinaVoti(Integer Array V, Integer N)`**:
* Implementa un algoritmo semplice (es. Bubble Sort) per ordinare dal più piccolo al più grande.
##### Funzione `mostraVotiFiltrati(Integer Array V, Integer N)`**:
*   Ciclo `For i = 2 to N-1`: (partendo dall'indice 2 escludiamo i primi due).
*   Output `V[i]`.
#### Esercizio 2
##### Soluzione A (più semplice)
La prima soluzione prevede di utilizzare un vettore di interi che contenga tutti i voti. Per ordinarlo, useremo il solito algoritmo di selection sort:
```c
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
```

Fatto questo, potremo passare a creare una funzione per il calcolo della media, facendo particolare attenzione al fatto che stiamo usando dei valori decimali.

```c
double calcola_media(int libretto[], int n) {
    double somma = 0;
    // Partiamo dall'indice 2 per saltare i due minimi dopo l'ordinamento
    for (int i = 2; i < n; i++) {
        somma += libretto[i];
    }
    return somma / (n - 2);
}
```

Potremo quindi calcolare il voto di ingresso con la seguente funzione:

 ```c
double calcolo_voto_laurea(double mediaPesata) {
    return (mediaPesata * 110.0) / 30.0;
}
```

A questo punto potremo implementare il nostro `main` come segue.

```c
#include <stdio.h>

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
	    fprintf(fp, "Materia %d:\t%d\n", i, libretto[i]);
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
```

Da notare che, per rispettare la traccia, abbiamo dovuto dapprima stampare i valori contenuti nel libretto, per poi andare ad ordinare il vettore e calcolare media e voto di laurea.
##### Soluzione B (più complessa)
Quest'implemementazione è più generalizzabile, ed include la possibilità di gestire i nomi delle materie. Per farlo, utilizzeremo un'apposita `struct`:

```c
typedef struct {
    char nome[50];
    int voto;
} Esame;
```

La funzione `ordina_esami` dovrà quindi tenere conto di questa nuova struttura dati, per cui potremo modificarla come segue:

```c
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
```

Modifichiamo anche la funzione `calcola_media` come segue:

```c
double calcola_media(Esame libretto[], int n) {
    double somma = 0;
    for (int i = 2; i < n; i++) {
	    somma += libretto[i].voto;
	}
    return somma / (n - 2);
}
```

Il programma risultante sarà quindi:

```c
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

double calcola_media(Esame libretto[], int n) {
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
        fprintf(fp, "%s\t\t%d\n", nomi_test[i], voti_test[i]);
    }

    fprintf(fp, "Media: \t\t%.0f\n", mediaPesata);
    fprintf(fp, "Voto di laurea: \t%.0f\n", votoLaurea);

    fclose(fp);

    return 0;
}
```
