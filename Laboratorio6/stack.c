// Inclusion de librerias
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Node* crearNodo(int data) {
    Node* nodoNuevo = (Node *)malloc(sizeof(Node));

    if (nodoNuevo == NULL) {
        printf("Error: No se pudo reservar memoria para el nuevo nodo\n");
        return NULL;
    }

    nodoNuevo->data = data;
    nodoNuevo->next = NULL;

    return nodoNuevo;
}

Stack* crearStack() {
    Stack* stack = (Stack *)malloc(sizeof(Stack));
    
    if (stack == NULL) {
        printf("Error: No se pudo reservar memoria para el stack\n");
        return NULL;
    }

    stack->top = NULL;
    return stack;
}

void push(Stack* stack, int data) {
    if (stack == NULL) {
        printf("Error: Direccion de memoria de stack indefinido\n");
        return;
    }

    Node* nodoTop = crearNodo(data);
    
    if (nodoTop == NULL) {
        return;
    }

    if (stack->top == NULL) {
        stack->top = nodoTop;
    }

    nodoTop->next = stack->top;
    stack->top = nodoTop;

}


void pop() {

}

void top() {

}

void isEmpty() {

}

void freeList() {
    
}