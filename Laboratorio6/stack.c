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

Stack* initStack() {
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

    Node* nodoNuevo = crearNodo(data);
    
    if (nodoNuevo == NULL) {
        printf("Error: No se pudo reservar memoria para crear el nodo\n");
        return;
    }

    if (stack->top == NULL) {
        stack->top = nodoNuevo;
    }

    nodoNuevo->next = stack->top;
    stack->top = nodoNuevo;

}


void pop(Stack* stack) {
    if (stack == NULL) {
        printf("Error: Direccion de memoria de stack indefinido\n");
        return;
    }
    
    if (stack->top == NULL) {
        printf("Error: Stack vacio\n");
        return;
    }

    Node* nodoEliminado = stack->top;
    int dataEliminado = stack->top->data;
    stack->top = stack->top->next;
    free(nodoEliminado);

    return dataEliminado;
}

void top(Stack* stack) {
    if (stack == NULL) {
        printf("Error: Direccion de stack indefinida\n");
        return;
    }

    if (stack->top == NULL) {
        printf("Stack vacio\n");
        return;
    }

    return stack->top->data;
}

void isEmpty(Stack* stack) {
    if (stack == NULL) {
        printf("Error: Direccion de stack indefinida\n");
        return;
    }

    if (stack->top == NULL) {
        return 1;
    }

    return 0;
}

void freeList() {
    
}