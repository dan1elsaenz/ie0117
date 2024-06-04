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
