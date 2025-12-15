#include <stdio.h>

/*
 * Procedura di stampa.
 */
void stampaDati(char* nome, char* cognome, int eta) {
    printf("Nome:\t\t%s\n", nome);
    printf("Cognome:\t%s\n", cognome);
    printf("Eta':\t\t%d anni\n", eta);
}


int main() {
    // 1. Dichiarazione delle variabili
    char nome[50];
    char cognome[50];
    int eta;

    // 2. Gestione dell'input
    printf("Inserisci il tuo nome: ");
    // Leggiamo la stringa e controlliamo.
    if (scanf("%49s", nome) != 1) {
        printf("Errore: nome non valido.\n");
        return 1; // Interruzione del programma
    }

    printf("Inserisci il tuo cognome: ");
    if (scanf("%49s", cognome) != 1) {
        printf("Errore: cognome non valido.\n");
        return 1;
    }

    printf("Inserisci la tua eta': ");
    // Per l'età usiamo %d e l'operatore & per passare l'indirizzo della variabile a scanf.
    if (scanf("%d", &eta) != 1) {
        printf("Errore: eta' non valida.\n");
        return 1;
    }

    // 3. Chiamata alla procedura di stampa
    stampaDati(nome, cognome, eta);
    
    return 0;
}

