#include <stdio.h>

/*
 * Definizione della procedura di scrittura su file.
 * Usiamo const perché il nome del file deve essere inteso in sola lettura e non modificabile.
 */
void salvaDatiSuFile(char* nome, char* cognome, int eta, const char* nome_file) {
    // 1. Dichiarazione del puntatore a file
    FILE* file_puntatore;

    // 2. Apertura del file in modalità di lettura
    file_puntatore = fopen(nome_file, "w");

    // 3. Controllo dell'apertura
    // Se fopen non riesce ad aprire il file restituisce NULL.
    // Controllo fondamentale per evitare bug.
    if (file_puntatore == NULL) {
        printf("Errore critico durante l'apertura del file!");
    } else {
        // 4. Scrittura formattata su file mediante fprintf.
        fprintf(file_puntatore, "Nome:\t\t%s\n", nome);
        fprintf(file_puntatore, "Cognome:\t%s\n", cognome);
        fprintf(file_puntatore, "Eta':\t\t%d\n", eta);
        // 5. Chiusura del file
        fclose(file_puntatore);
    }
}

int main() {
    char nome[50];
    char cognome[50];
    int eta;

    printf("Inserisci il tuo nome: ");
    if (scanf("%49s", nome) != 1) {
        printf("Errore: nome non valido.\n");
        return 1;
    }

    printf("Inserisci il tuo cognome: ");
    if (scanf("%49s", cognome) != 1) {
        printf("Errore: cognome non valido.\n");
        return 1;
    }

    printf("Inserisci la tua eta': ");
    if (scanf("%d", &eta) != 1) {
        printf("Errore: eta' non valida.\n");
        return 1;
    }

    salvaDatiSuFile(nome, cognome, eta, "dati_utente.txt");

    return 0;
}


