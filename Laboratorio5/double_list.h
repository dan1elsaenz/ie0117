
#ifndef DOUBLE_LIST_H

#define DOUBLE_LIST_H

// Definicion del struct Node
typedef struct Node {
    int data; // Dato guardado en cada elemento

    // Posiciones de los elementos contiguos
    struct Node* next;
    struct Node* prev;
} Node;


/*
 * crearNodo() reserva la memoria dinamica para crear un nodo
 * nuevo, inicializa los nodos previo y siguiente en NULL y le
 * asigna el data correspondiente
 * 
 * @param1 int data: Dato entero que guarda el nodo
 * @return nodoNuevo: Nodo creado 
 */
Node* crearNodo(int data);


/*
 * insertarInicio() agrega un nuevo nodo al inicio de la lista
 * 
 * @param1 Node** head: Puntero a la direccion del puntero head de la lista
 * @param2 int data: Dato entero para agregar al inicio de la lista
 */
void insertarInicio(Node **head, int data);


/*
 * insertarFinal() agrega un nodo seguido del ultimo elemento de la lista
 *
 * @param1 Node* head: Direccion del nodo head para recorrer la lista
 * @param2 int data: Dato entero para agregarle al nodo creado
 */
void insertarFinal(Node* head, int data);


/*
 * insertarIndex() agrega un nodo en un indice indicado en la lista
 *
 * @param1 Node** head: Puntero a la direccion del nodo head
 * @param2 int data: Entero para agregarle al nuevo nodo
 * @param3 int posicion: Indice de insercion del nuevo nodo
 */
void insertarIndex(Node** head, int data, int posicion);


/*
 * eliminarElemento() quita un nodo de la lista basado en el contenido de su data
 * 
 * @param1 Node** head: Direccion al puntero de head
 * @param2 int dataEliminar: Dato entero para eliminar al nodo que lo contiene
 */
void eliminarElemento(Node** head, int dataEliminar);


/*
 * buscarElemento() busca un nodo basado en el contenido de su variable data
 * 
 * @param1 Node* head: Puntero al nodo head
 * @param2 int dataBuscar: Entero a buscar entre el contenid de los nodos
 */
void buscarElemento(Node* head, int dataBuscar);


/*
 * recorrerListaAdelante() imprime el contenido de cada uno de
 * los nodos en orden de inicio a fin
 * 
 * @param1 Node* head: Puntero al nodo head de la lista
 */
void recorrerListaAdelante(Node* head);


/*
 * recorrerListaAtras() imprime el contenido de cada uno de
 * los nodos en orden inverso de fin a inicio
 * 
 * @param1 Node* head: Puntero al nodo head de la lista
 */
void recorrerListaAtras(Node* head);


/*
 * freeList() libera la memoria reservada de cada uno de los nodos
 * utilizados en la lista
 * 
 * @param1: Node* head: Puntero al nodo head de la lista
 */
void freeList(Node* head);

#endif /* DOUBLE_LIST_H */

