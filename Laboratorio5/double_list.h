
#ifndef DOUBLE_LIST_H

#define DOUBLE_LIST_H

// Definicion del struct Node
typedef struct Node {
    int data; // Dato guardado en cada elemento

    // Posiciones de los elementos contiguos
    struct Node* next;
    struct Node* prev;
} Node;

Node* crearNodo(int data);

void insertarInicio(Node **head, int data);

void insertarFinal(Node* head, int data);

void insertarIndex(Node** head, int data, int posicion);

void eliminarElemento(Node** head, int dataEliminar);

void buscarElemento(Node* head, int dataBuscar);

void recorrerListaAdelante(Node* head);

void recorrerListaAtras(Node* head);

void freeList(Node* head);

#endif /* DOUBLE_LIST_H */

