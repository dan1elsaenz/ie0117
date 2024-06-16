// Inclusion de librerias
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


/*
 * crearNodo() reserva memoria del heap para crear un struct Node,
 * inicializa data con el argumento de la funcion y next a NULL
 * 
 * @param1 int data: Data a agregar al nodo
 * @return Node* nodoNuevo: Puntero al nodo creado
 */
Node* crearNodo(int data) {
    Node* nodoNuevo = (Node *)malloc(sizeof(Node));

    if (nodoNuevo == NULL) {
        printf("Error: No se pudo reservar memoria para el nuevo nodo\n");
        return NULL;
    }

    // Asignacion de las propiedades del struct predeterminadas
    nodoNuevo->data = data;
    nodoNuevo->next = NULL;

    return nodoNuevo;
}


/*
 * initStack() inicializa la estructura de datos Stack con memoria dinamica,
 * declara top en NULL inicialmente
 * 
 * @return Stack* stack: Stack creado
 */
Stack* initStack(int* stack_running) {
    Stack* stack = (Stack *)malloc(sizeof(Stack));
    
    if (stack == NULL) {
        printf("Error: No se pudo reservar memoria para el stack\n");
        return NULL;
    }

    *stack_running = 1;
    stack->top = NULL;
    return stack;
}


/*
 * push() agrega un nuevo nodo en la posicion top del stack
 * 
 * @param1 Stack* stack: Puntero al struct Stack
 * @param2 int data: Data que se desea agregar al nodo nuevo
 */
void push(Stack* stack, int data) {
    if (stack == NULL) {
        printf("Error: Direccion de memoria de stack indefinido\n");
        return;
    }

    Node* nodoNuevo = crearNodo(data);
    
    if (nodoNuevo == NULL) {
        return;
    }

    nodoNuevo->data = data;

    if (isEmpty(stack)) {
        stack->top = nodoNuevo;
        return;
    }

    // Cambio del nodo top al nuevo nodo
    nodoNuevo->next = stack->top;
    stack->top = nodoNuevo;
}


/*
 * pop() elimina el nodo ubicado en el top del stack
 * 
 * @param1 Stack* stack: Puntero al stack utilizado
 * @return int datoEliminado: Data eliminada del nodo top del stack
 *         / -1 en caso de error
 */
int pop(Stack* stack) {
    if (stack == NULL) {
        printf("Error: Direccion de memoria de stack indefinido\n");
        return -1;
    }
    
    if (isEmpty(stack)) {
        printf("Error: No se pudo extraer nada porque el stack esta vacio\n");
        return -1;
    }

    // Actualizar nodos y contenido
    Node* nodoEliminado = stack->top;
    int dataEliminado = stack->top->data;
    stack->top = stack->top->next;

    // Liberar memoria
    free(nodoEliminado);
    nodoEliminado = NULL;

    return dataEliminado;
}


/*
 * top() devuelve el data del nodo top del stack
 *
 * @param1 Stack* stack: Puntero al stack empleado
 * @return int data: Data del nodo top / -1 en caso de error
 */
int top(Stack* stack) {
    if (stack == NULL) {
        printf("Error: Direccion de stack indefinida\n");
        return -1;
    }

    if (isEmpty(stack)) {
        printf("Stack vacio. No hay contenido para extraer\n");
        return -1;
    }

    return stack->top->data;
}


/*
 * isEmpty() revisa si el stack esta vacio
 * 
 * @param1 Stack* stack: Puntero al stack
 * @return int estaVacio: Vacio: 1 | Error: -1 | +1 nodos: 0
 */
int isEmpty(Stack* stack) {
    int estaVacio = 0;

    if (stack == NULL) {
        printf("Error: Direccion de stack indefinida\n");
        estaVacio = -1;
    }

    if (stack->top == NULL) {
        estaVacio = 1;
    }

    return estaVacio;
}


/*
 * printStack() imprime el stack completo nodo por nodo
 * 
 * @param1 Stack* stack: Stack empleado
 */
void printStack(Stack* stack) {
    if (stack == NULL) {
        printf("Error: Direccion de stack indefinida\n");
        return;
    }

    Node* actual = stack->top;
    while (actual != NULL) {
        printf("%d -> ", actual->data);
        actual = actual->next;
    }
    printf("NULL\n");
}


/*
 * freeStack() libera la memoria reservada para formar el stack
 * por medio de free()
 * 
 * @param1 Stack* stack: Stack utilizado
 */
void freeStack(Stack* stack) {
    Node* actual = stack->top;
    Node* next = NULL;

    while (actual != NULL) {
        next = actual->next;
        free(actual);
        actual = next;
    }

    free(stack);
}