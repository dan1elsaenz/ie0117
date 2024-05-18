#include <stdio.h>

int busquedaLineal (int array[], int objetivo, int longitud) {
    int posicion = 0;

    for (posicion = 0; posicion < longitud; posicion++) {
        if (array[posicion] == objetivo) {
            return posicion;
        }
    }

    return -1;
}

int busquedaBinaria (int array[], int objetivo, int limiteSuperior) {
    int valorMedio = 0;
    int limiteInferior = 0;
    
    while (limiteInferior <= limiteSuperior) {
        valorMedio = limiteInferior + (limiteSuperior - limiteInferior)/2;

        printf("%d\n", valorMedio);

        if (array[valorMedio] == objetivo) {
            return valorMedio;
        }

        else if (array[valorMedio] < objetivo) {
            limiteInferior = valorMedio + 1;
        }

        else if (array[valorMedio] > objetivo) {
            limiteSuperior = valorMedio - 1;
        }
    }

    return -1;
}

int busquedaBinariaRecursiva(int array[], int objetivo, int limiteInferior, int limiteSuperior) {
    int valorMedio = 0;
    
    if (limiteInferior <= limiteSuperior) {
        valorMedio = limiteInferior + (limiteSuperior - limiteInferior)/2;

        if (array[valorMedio] == objetivo) {
            return valorMedio;
        }

        else if (array[valorMedio] > objetivo) {
            return busquedaBinariaRecursiva(array, objetivo, limiteInferior, valorMedio - 1);
        }

        else if (array[valorMedio] < objetivo) {
            return busquedaBinariaRecursiva(array, objetivo, valorMedio + 1, limiteSuperior);
        }
    }

    return -1;
}


int main() {
    int array[] = {2, 4, 6, 23, 56, 79};

    int longitud = sizeof(array)/sizeof(array[0]);

    int objetivo = 0;
    printf("Ingrese un numero para buscarlo en el arreglo numerico: ");

    if (scanf("%d", &objetivo) != 1) {
        printf("Entrada no numerica invalida\n");
        return 1;
    }


    printf("Busqueda lineal\n");
    int resultadoLineal = busquedaLineal(array, objetivo, longitud);

    if (resultadoLineal == -1) {
        printf("El numero ingresado no se encuentra en el arreglo\n");
    }
    else {
        printf("Posicion: %d\n\n", resultadoLineal);
    }


    printf("Busqueda binaria\n");
    int resultadoBinaria = busquedaBinaria(array, objetivo, longitud);

    if (resultadoBinaria == -1) {
        printf("El numero ingresado no se encuentra en el arreglo\n");
    }
    else {
        printf("Posicion: %d\n\n", resultadoBinaria);
    }

    printf("Busqueda binaria recursiva\n");
    int resultadoBinariaRecursiva = busquedaBinariaRecursiva(array, objetivo, 0, longitud);

    if (resultadoBinariaRecursiva == -1) {
        printf("El numero ingresado no se encuentra en el arreglo\n");
    }
    else {
        printf("Posicion: %d\n\n", resultadoBinariaRecursiva);
    }

    return 0;
}
