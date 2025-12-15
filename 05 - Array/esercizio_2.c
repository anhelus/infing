#include <stdio.h>
#include <stdlib.h>

int main() {
    char str_int[] = "123";
    char str_flt[] = "1.23";
    char output[64];
    int out_int = atoi(str_int);
    double out_flt = atof(str_flt);
    sprintf(output, "Intero: %d\nFloat: %f", out_int, out_flt);
    printf(output);
}