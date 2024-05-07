/*
 * Laboratorio 3 IE-0117
 * Ejercicio 3
 * Daniel Saenz Obando - C37099
 */

// Headers utilizados
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANO_PREDETERMINADO 5

/*
 * Variable global para almacenar el tamano de la matriz y facilitar 
 * el paso de la matriz como argumento y su manipulacion
 */
int tamano = 0;

/*
 * getMatrixSize() recibe la entrada del usuario correspondiente
 * al tamano de matriz y verifica que se encuentre dentro del
 * rango permitido (1-10)
 * @return El tamano de la matriz que se va a utilizar
 */

int getMatrixSize() {
    int tamanoUsuario = 0;

    printf("Tamano de matriz nxn (1-10): ");

    if ((scanf("%d", &tamanoUsuario) == 0) || (!(tamanoUsuario >= 1 && tamanoUsuario <= 10))) {
        tamanoUsuario = TAMANO_PREDETERMINADO;
        printf("Valor ingresado no corresponde a un numero entero entre 1-10\n");
        printf("Valor predeterminado de tamano: %d\n\n", TAMANO_PREDETERMINADO);
    }

    return tamanoUsuario;
}

/*
 * randomMatrix() llena una matriz de numeros aleatorios binarios y la imprime
 * @param matrix[][tamano] Matriz a llenar
 */

void randomMatrix(int matrix[][tamano]) {
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            matrix[i][j] = rand() % 2;
        }
    }

    printf("La matriz utilizada corresponde a:\n");
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/*
 * minimo() determina el numero minimo entre tres parametros enteros
 * @param n1 Primer numero
 * @param n2 Segundo numero
 * @param n3 Tercer numero
 * @return Numero minimo entre los tres
 */

int minimo(int n1, int n2, int n3){
    int min = n1;

    if (n2 < min) {
        min = n2;
    }
    
    if (n3 < min) {
        min = n3;
    }

    return min;
}

/*
 * findLargestSquare() determina el mayor cuadrado de 1s que se puede formar en la matriz
 * @param matrix[][tamano] Matriz cuadrada utilizada
 * @return largestSquareSize Mayor lado posible del cuadrado de 1s
 */

int findLargestSquare(int matrix[][tamano]) {
    int largestSquareSize = 0;

    for (int i=0; i < tamano; i++) {
        for (int j=0; j < tamano; j++) {
            if ((matrix[i][j] != 0) && i!=0 && j!=0){
                matrix[i][j] = 1 + minimo(matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]);
                if (largestSquareSize < matrix[i][j]) {
                    largestSquareSize = matrix[i][j];
                }
            }
            else if (i==0 || j==0) {
                if (largestSquareSize < matrix[i][j]) {
                    largestSquareSize = matrix[i][j];
                }
            }
        }
    }

    // printf("\n");
    // for (int i = 0; i < tamano; i++) {
    //     for (int j = 0; j < tamano; j++) {
    //         printf("%d ", matrix[i][j]);
    //     }
    //     printf("\n");
    // }

    return largestSquareSize;
}

int main() {
    // Tiempo como seed para la generacion de numeros aleatorios
    srand(time(NULL));

    tamano = getMatrixSize();

    int matrix[tamano][tamano];

    randomMatrix(matrix); // Matriz de numeros aleatorios

    int largestSquareSize = findLargestSquare(matrix);
    printf("El tamano del cuadrado mas grande de unos es: %dx%d\n", largestSquareSize, largestSquareSize);

    return 0;
}
