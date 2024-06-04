#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"

/*
 * main() corresponde al punto de entrada del proyecto
 * Se demuestra el funcionamiento correcto de las listas doblemente enlazadas
 * 
 * @return 0 si no ocurrieron errores en ejecucion
 */
int main() {
    // Declaracion del nodo head
    Node* head = NULL;

    // Creacion inicial de una lista del 1-6
    insertarInicio(&head, 1);
    insertarFinal(head, 2);
    insertarFinal(head, 3);
    insertarFinal(head, 4);
    insertarFinal(head, 5);
    insertarFinal(head, 6);

    printf("Lista inicial:\n");
    recorrerListaAdelante(head);
    printf("\n");

    insertarIndex(&head, 0, 0); // Agregar nodo al inicio
    insertarIndex(&head, 7, 3); // Agregar nodo al final

    printf("Lista despues del insert:\n");
    recorrerListaAdelante(head);
    printf("\n");

    // Eliminar nodos basado en su contenido
    eliminarElemento(&head, 5);

    eliminarElemento(&head, 6);

    printf("Lista despues de la eliminacion:\n");
    recorrerListaAdelante(head);
    printf("\n");

    printf("Busqueda de contenido de nodo:\n");
    buscarElemento(head, 4);
    printf("\n");

    printf("Recorrido hacia atras de la lista:\n");
    recorrerListaAtras(head);

    freeList(head); // Liberacion de la memoria reservada para cada nodo

    return 0;
}

