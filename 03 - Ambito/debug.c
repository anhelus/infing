#include <stdio.h>

int calcola_perimetro_quadrato(int lato) {
    int perimetro = lato * 4;
    return perimetro;
}

int calcola_area_quadrato(int lato) {
    int area = lato * lato;
    return area;
}

int main() {
    int lato = 5;
    calcola_area_quadrato(lato);
    int perimetro = calcola_perimetro_quadrato(lato);
    int area = printf("Il valore dell'area è: %d \n", area);
    printf("Il valore del perimetro è: %d \n", perimetro);
    return 0;
}
