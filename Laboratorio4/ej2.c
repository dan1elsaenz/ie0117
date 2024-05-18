/*
 * Laboratorio 4 - IE-0117
 * Ejercicio 2
 * Daniel Saenz Obando - C37099
 */

// Biblioteca
#include <stdio.h>

/*
 * encontrarMinimo() busca el menor numero por medio de una busqueda lineal
 * @param1 array[] Arreglo de numeros enteros
 * @param2 longitud Largo del arreglo
 * @return numeroMenor
 */

int encontrarMinimo(int array[], int longitud) {
    int numeroMenor = array[0];

    for (int i = 1; i < longitud; i++) {
        if (numeroMenor > array[i]) {
            numeroMenor = array[i];
        }
    }

    return numeroMenor;
}


/*
 * encontrarMaximo() busca el mayor numero por medio de una busqueda lineal
 * @param1 array[] Arreglo de numeros enteros
 * @param2 longitud Largo del arreglo
 * @return numeroMayor
 */
int encontrarMaximo(int array[], int longitud) {
    int numeroMayor = array[0];

    for (int i = 1; i < longitud; i++) {
        if (numeroMayor < array[i]) {
            numeroMayor = array[i];
        }
    }

    return numeroMayor;
}

/* 
 * encontrarMinMax_ptr() encuentra el numero maximo y minimo por medio de una
 * busqueda lineal utilizando punteros
 * @param1 * arreglo Puntero al primer elemento del arreglo de numeros enteros
 * @param2 * minimo Puntero a la variable minimo_ptr del main
 * @param3 * maximo Puntero a la variable maximo_ptr del main
 * @param4 longitud Entero que contiene el largo del arreglo
 * @return No retorna ningun valor
 */

void encontrarMinMax_ptr(int * arreglo, int * minimo, int * maximo, int longitud) {
    *minimo = *arreglo;
    *maximo = *arreglo;
    

    for (int i = 1; i < longitud; i++) {
        if (*(arreglo + i) < *minimo) {
            *minimo = *(arreglo + i);
        }
        
        
        if (*(arreglo + i) > *maximo) {
            *maximo = *(arreglo + i);
        }
    }
}


/*
 * main()
 * Punto de entrada al programa donde se ejecuta la logica principal
 * Se llaman las funciones anteriores
 * @return 0 si no ocurrieron errores
 */
int main() {
    int array[] = {21, 24, 65, -3, 56, 73, 35, 15};

    int longitud = sizeof(array)/sizeof(array[0]);

    // Definicion de las variables empleadas en el programa
    int minimo = 0;
    int maximo = 0;
    int minimo_ptr = 0;
    int maximo_ptr = 0;

    minimo = encontrarMinimo(array, longitud);
    maximo = encontrarMaximo(array, longitud);

    printf("El minimo encontrado en el arreglo es %d y el maximo %d\n", minimo, maximo);


    encontrarMinMax_ptr(array, &minimo_ptr, &maximo_ptr, longitud);

    printf("El minimo encontrado con punteros es: %d\n", minimo_ptr);
    printf("El maximo encontrado con punteros es %d\n", maximo_ptr);

    return 0;
}
