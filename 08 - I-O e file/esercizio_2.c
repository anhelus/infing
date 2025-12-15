#include <stdio.h>  // Libreria standard per I/O (printf, scanf, fopen, fprintf, fclose, etc.)

/*
 * Definizione della procedura di scrittura su file.
 * Il suo unico scopo è ricevere i dati e scriverli su un file specificato.
 * Usiamo const perché il nome del file deve essere inteso in sola lettura e non modificabile.
 */
void salvaDatiSuFile(char* nome, char* cognome, int eta, const char* nome_file) {
    // 1. Dichiarazione del puntatore a file
    FILE* file_puntatore;

    // 2. Apertura del file in modalità di lettura
    file_puntatore = fopen(nome_file, "w");

    // 3. Controllo dell'apertura
    // Se fopen non riesce ad aprire il file (es. per mancanza di permessi), restituisce NULL.
    // È FONDAMENTALE controllare questo caso per evitare crash.
    if (file_puntatore == NULL) {
        printf("Errore critico durante l'apertura del file!");
    } else {
        // 4. Scrittura formattata su file mediante fprintf.
        fprintf(file_puntatore, "Nome: %s\n", nome);
        fprintf(file_puntatore, "Cognome: %s\n", cognome);
        fprintf(file_puntatore, "Eta': %d\n", eta);
        // 5. Chiusura del file (fondamentale!)
        fclose(file_puntatore);
    }
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

    // 3. Chiamata alla procedura di salvataggio
    salvaDatiSuFile(nome, cognome, eta, "dati_utente.txt");

    return 0;
}


