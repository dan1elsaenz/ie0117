#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANO_PREDETERMINADO 5

int tamano = 0;

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

    return largestSquareSize;
}

int main() {
    srand(time(NULL));

    tamano = getMatrixSize();

    int matrix[tamano][tamano];

    randomMatrix(matrix); // Matriz de numeros aleatorios

    int largestSquareSize = findLargestSquare(matrix);
    printf("El tamano del cuadrado mas grande de unos es: %dx%d\n", largestSquareSize, largestSquareSize);

    return 0;
}

