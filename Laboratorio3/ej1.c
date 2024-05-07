/*
 * Laboratorio 3 IE-0117
 * Ejercicio 1
 * Daniel Saenz Obando - C37099
 */

// Header utilizado
#include <stdio.h>

/*
 * main() calcula los primeros 100 numeros triangulares
 * por medio de un for loop que añade el indice del bucle
 * a una variable total definida inicialmente
 * 
 * @return 0 si el codigo se ejecuto correctamente
 */

int main() {
    int total = 0;

    for (int index = 0; index<100; index++) {
        total += index;
        printf("%d ", total);
    }
    printf("\n"); // Salto de linea al final

    return 0;
}