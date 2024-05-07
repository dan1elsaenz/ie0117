#include <stdio.h>

int main() {
    int total = 0;

    for (int index = 0; index<100; index++) {
        total += index;
        printf("%d ", total);
    }
    printf("\n"); // Salto de linea al final

    return 0;
}
