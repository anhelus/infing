#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main() {    
    int V[5] = { 2, 3, 5, 13, 20 };
    int key = 13;
    int low = 0;
    int high = 4;
    bool found = false;
    int medium;

    while (low <= high) {
        medium = floor((low+high)/2);
        if (V[medium] == key) {
            found = true;
            break;
        } else  {
            if (key < V[medium]) {
                high = medium - 1;            
            } else {
                low = medium + 1;
            }
        }
    }
    if(found) {
        printf("Sono il Mastro di Chiavi! La chiave %d è presente!", key);
    } else {
        printf("Sono il Mastro di Chiavi! La chiave %d non è presente!", key);
    }

    return 0;
}