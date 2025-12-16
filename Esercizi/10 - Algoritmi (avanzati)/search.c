#include "search.h"
#include <stdbool.h>

bool linear_search(int* V, int size, int k) {
    for(int i = 0; i < size; i++) {
        if(V[i] == k)
            return true;
    }
    return false;
}

bool binary_search(int* V, int size, int k) {
    int low = 0;
    int high = size - 1;
    int medium;

    while (low <= high) {
        medium = (low+high)/2;
        if (V[medium] == k) {
            return true;
        } else  {
            if (k < V[medium]) {
                high = medium - 1;            
            } else {
                low = medium + 1;
            }
        }
    }
    return false;
}
