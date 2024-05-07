#include <stdio.h>

int factorial(int n) {
    int i = 1;

    while (n > 1) {
        i = i * n;
        n = n - 1;
    }
    return i;
}

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
