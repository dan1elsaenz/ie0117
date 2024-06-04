#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"


int main() {
    Node* head = NULL;

    insertarInicio(&head, 1);
    insertarFinal(head, 2);
    insertarFinal(head, 3);
    insertarFinal(head, 4);
    insertarFinal(head, 5);
    insertarFinal(head, 6);

    printf("Lista inicial:\n");
    recorrerListaAdelante(head);
    printf("\n");

    insertarIndex(&head, 0, 0);
    insertarIndex(&head, 7, 3);

    printf("Lista despues del insert:\n");
    recorrerListaAdelante(head);
    printf("\n");

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

    freeList(head);

    return 0;
}

