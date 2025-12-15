#include <stdio.h>

typedef struct studente
{
    char nome[32];
    char cognome[32];
    int matricola;
} STUDENTE;

typedef union lettura
{
    long lettura_int;
    float lettura_float;
} LETTURA;

int main() {
    STUDENTE w_white = {
        .nome = "Walter",
        .cognome = "White",
        .matricola =  123456
    };

    LETTURA l_gas = {
        .lettura_float = 12.34,
    };

    printf("Nome:\t\t%s\nCognome:\t%s\nMatricola:\t%d\n", w_white.nome, w_white.cognome, w_white.matricola);
    printf("Lettura contatore gas:%f\n", l_gas.lettura_float);
}
