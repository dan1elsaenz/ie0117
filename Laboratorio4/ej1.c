/*
 * Laboratorio 4 - IE-0117
 * Ejercicio 1
 * Daniel Saenz Obando - C37099
 */

// Biblioteca
#include <stdio.h>

/*
 * busquedaLineal() busca un numero objetivo por medio de un for loop
 * @param1 array[] Arreglo de numeros enteros donde se busca el numero
 * @param2 objetivo Numero entero objetivo de la busqueda
 * @param3 longitud Entero que contiene la longitud del arreglo numerico
 * @return posicion donde se encuentra el objetivo / -1 si no se encontro
 */
int busquedaLineal (int array[], int objetivo, int longitud) {
    int posicion = 0;

    for (posicion = 0; posicion < longitud; posicion++) {
        if (array[posicion] == objetivo) {
            return posicion;
        }
    }

    return -1;
}

/*
 * busquedaBinaria() busca un numero objetivo por medio de la estrategia
 * de busqueda binaria donde se divide la entrada de analisis a la mitad
 * cada repeticion
 * @param1 array[] Arreglo de numeros enteros donde se busca el numero
 * @param2 objetivo Numero entero objetivo de la busqueda
 * @param3 limiteSuperior Entero que contiene la longitud del arreglo
 * numerico inicialmente
 * @return posicion donde se encuentra el objetivo / -1 si no se encontro
 */

int busquedaBinaria (int array[], int objetivo, int limiteSuperior) {
    int valorMedio = 0; // Valor medio del rango analizado en cada repeticion
    int limiteInferior = 0; // Limite inferior de analisis para cada repeticion
    
    while (limiteInferior < limiteSuperior) {
        valorMedio = limiteInferior + (limiteSuperior - limiteInferior)/2;

        if (array[valorMedio] == objetivo) {
            return valorMedio;
        }

        // Cambio de los limites de analisis
        else if (array[valorMedio] < objetivo) {
            limiteInferior = valorMedio + 1;
        }

        else if (array[valorMedio] > objetivo) {
            limiteSuperior = valorMedio - 1;
        }
    }

    return -1;
}


/*
 * busquedaBinariaRecursiva() busca recursivamente por medio de una busqueda
 * binaria un entero objetivo
 * @param1 array[] Arreglo de numeros enteros donde se busca el numero
 * @param2 objetivo Numero entero objetivo de la busqueda
 * @param3 limiteInferior Entero inicialmente 0 que contiene el limite inferior de la busqueda
 * @param4 limiteSuperior Entero que contiene la longitud del arreglo
 * numerico inicialmente
 * @return posicion donde se encuentra el objetivo / -1 si no se encontro
 */

int busquedaBinariaRecursiva(int array[], int objetivo, int limiteInferior, int limiteSuperior) {
    int valorMedio = 0;
    
    if (limiteInferior < limiteSuperior) {
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

/*
 * main() Punto de entrada del programa donde se llaman las funciones
 * definidas anteriormente
 * Procesa las entradas numericas del usuario del entero objetivo
 * Valida las salidas de las funciones
 * @return 0 si se ejecuto el programa sin errores
 */

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
