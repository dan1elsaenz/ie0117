#include <stdio.h>

int encontrarMinimo(int array[], int longitud) {
    int numeroMenor = array[0];

    for (int i = 1; i < longitud; i++) {
        if (numeroMenor > array[i]) {
            numeroMenor = array[i];
        }
    }

    return numeroMenor;
}

int encontrarMaximo(int array[], int longitud) {
    int numeroMayor = array[0];

    for (int i = 1; i < longitud; i++) {
        if (numeroMayor < array[i]) {
            numeroMayor = array[i];
        }
    }

    return numeroMayor;
}

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


int main() {
    int array[] = {21, 24, 65, -3, 56, 73, 35, 15};

    int longitud = sizeof(array)/sizeof(array[0]);

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
