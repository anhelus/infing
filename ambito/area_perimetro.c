#include <stdio.h>

// Usiamo una variabile globale, quindi visibile ovunque nel programma
int lato = 5;

// Rimuoviamo il parametro in quanto le variabili locali hanno precedenza su quelle globali!
int calcola_area_quadrato() {
    int area = lato * lato;
    return area;
}

int calcola_perimetro_quadrato() {
    int perimetro = lato * 4;
    return perimetro;
}

int main() {
    int lato = 5;
    int area = calcola_area_quadrato();
    int perimetro = calcola_perimetro_quadrato();
    printf("Il valore dell'area è: %d \n", area);
    printf("Il valore del perimetro è: %d \n", perimetro);
    return 0;
}
