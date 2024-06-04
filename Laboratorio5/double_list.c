#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"

// Evitar repeticion del codigo
Node* crearNodo(int data) {
    Node* nodoNuevo = (Node *)malloc(sizeof(Node));

    if (nodoNuevo == NULL) {
        printf("Error: No se pudo crear el nodo\n");
        return NULL;
    }

    nodoNuevo->data = data;
    nodoNuevo->prev = NULL;
    nodoNuevo->next = NULL;
 
    return nodoNuevo;
}

void insertarInicio(Node **head, int data) {
    if (head == NULL) {
        printf("Error: Puntero a nodo head invalido\n");
        return;
    }
    
    Node* nodoInicial = crearNodo(data);

    if (nodoInicial == NULL) {
        printf("Error: No se pudo reservar memoria para el nuevo nodo\n");
        return;
    }
    
    if (*head == NULL) {
        *head = nodoInicial;
        return;
    }
    
    nodoInicial->next = *head;
    (*head)->prev = nodoInicial;
    *head = nodoInicial;
}

void insertarFinal(Node* head, int data) {
    
    if (head == NULL) {
        printf("Error: Nodo head no definido\n");
        return;
    }

    Node* nodoFinal = crearNodo(data);

    if (nodoFinal == NULL) {
        printf("Error: No se pudo reservar memoria para el nuevo nodo\n");
        return;
    }

    Node* actual = head;
    while (actual->next != NULL) {
        actual = actual->next;
    }

    actual->next = nodoFinal;
    nodoFinal->prev = actual;
}

void insertarIndex(Node** head, int data, int posicion) {
    if (head == NULL) {
        printf("Error: Puntero a nodo head invalido\n");
        return;
    }

    else if (posicion < 0) {
        printf("Error: %d no es una posicion valida entera positiva\n", posicion);
        return;
    }

    else if (posicion == 0) {
        insertarInicio(head, data);
        return;
    }

    else if (*head == NULL) {
        printf("Error: Nodo head no esta definido y no se puede agregar elemento en la posicion %d\n", posicion);
        return;
    }

    int contador = 0;
    Node* actual = *head;

    while (contador != posicion && actual->next != NULL) {
        actual = actual->next;

        contador++;
    }

    if (contador+1 == posicion) {
        insertarFinal(*head, data);
        return;
    }

    else if (contador+1 < posicion) {
        printf("Error: El indice del ultimo nodo es %d. La posicion %d ingresada esta fuera de los limites de la lista\n", contador, posicion);
        return;
    }

    Node* nuevoNodo = crearNodo(data);

    if (nuevoNodo == NULL) {
        printf("Error: No se pudo reservar memoria para el nuevo nodo\n");
        return;
    }

    nuevoNodo->prev = actual->prev;
    actual->prev->next = nuevoNodo;
    actual->prev = nuevoNodo;
    nuevoNodo->next = actual;

}

void eliminarElemento(Node** head, int dataEliminar) {
    
    if (head == NULL) {
        printf("Error: Puntero a nodo head invalido\n");
        return;
    }
    
    else if (*head == NULL) {
        printf("Error: Nodo head no definido\n");
        return;
    }
    
    Node* actual = *head;
    
    while (actual != NULL) {
        if (actual->data == dataEliminar) {
            break;
        }
        
        actual = actual->next;
    }

    if (actual == NULL) {
        printf("No se encontro el nodo con %d en su data\n", dataEliminar);
        return;
    }

    else if (actual->prev == NULL) {
        *head = actual->next;
    }

    else if (actual->next == NULL) {
        actual->prev->next = NULL;
    }
    else {
        actual->next->prev = actual->prev;
        actual->prev->next = actual->next;
    }

    free(actual);
    actual = NULL;
}

void buscarElemento(Node* head, int dataBuscar) {

    if (head == NULL) {
        printf("Error: Nodo head no definido\n");
        return;
    }

    Node* actual = head;
    int contador = 0;
    while (actual != NULL) {
        if (actual->data == dataBuscar) {
            printf("Dato %d encontrado en el nodo %d\n", dataBuscar, contador);
            return;
        }
        
        actual = actual->next;
        contador++;
    }

    printf("No se encontro %d en la lista enlazada\n", dataBuscar);
}

void recorrerListaAdelante(Node* head) {
    if (head == NULL) {
        printf("Error: Nodo head no definido\n");
        return;
    }


    Node* actual = head;
    while (actual != NULL) {
        printf("%d - ", actual->data);
        actual = actual->next;
    }

    printf("NULL\n");
}


void recorrerListaAtras(Node* head) {
    if (head == NULL) {
        printf("Error: Nodo head no definido\n");
        return;
    }
    
    Node* final = head;

    while (final->next != NULL) {
        final = final->next;
    }

    while (final != NULL) {
        printf("%d - ", final->data);
        final = final->prev;
    }
    printf("NULL\n");

}

void freeList(Node* head) {
    Node* actual = head;
    Node* next = NULL;

    while (actual != NULL) {
        next = actual->next;
        free(actual);
        actual = next;
    }
}
