/*
 * Laboratorio 3 IE-0117
 * Ejercicio 2
 * Daniel Saenz Obando - C37099
 */

// Header utilizado
#include <stdio.h>

/*
 * factorial() calcula el factorial de un numero entero n
 * @param n Numero entero positivo
 * @return i Resultado del factorial
 */

int factorial(int n) {
    int i = 1;

    while (n > 1) {
        i = i * n;
        n = n - 1;
    }
    return i;
}

/*
 * main() verifica el ingreso de un numero entero positivo
 * y calcula su factorial
 * 
 * @return 0 si se ejecuto correctamente el codigo del programa
 */

int main() {
    int numeroFactorial = 0;

    printf("Ingrese el numero al que desea obtener el factorial: ");

    if ((scanf("%d", &numeroFactorial) == 1) && (numeroFactorial > 0)) {
        int resultado = factorial(numeroFactorial);
        printf("El factorial de %d es %d\n", numeroFactorial, resultado);
    }
    
    else {
        printf("Ingrese un numero entero positivo.\n");
    }

    return 0;
}
