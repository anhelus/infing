#include <stdio.h>
#include <stdbool.h>
#include "sorting.h"
#include "search.h"

int main() {
    int V[] = {5, 2, 20, 13, 3};
    int size = sizeof(V) / sizeof(V[0]);
    selection_sort(V, size);
    bool found = binary_search(V, size, 20);
    if (found) {
        printf("Trovato");
    } else {
        printf("Non ci sta");
    }
}