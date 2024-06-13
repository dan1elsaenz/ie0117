#ifndef STACK_H

#define STACK_H 

/*
 * struct Node contiene el data que se guarda en el nodo y
 * el siguiente nodo de la lista enlazada
 */
typedef struct Node {
    int data;
    struct Node* next;
} Node;


/*
 * struct Stack contiene el puntero al Node* top para la lista enlazada
 */
typedef struct Stack {
    Node* top;
} Stack;


/*
 * crearNodo() reserva memoria del heap para crear un struct Node,
 * inicializa data con el argumento de la funcion y next a NULL
 * 
 * @param1 int data: Data a agregar al nodo
 * @return Node* nodoNuevo: Puntero al nodo creado
 */
Node* crearNodo(int data);


/*
 * initStack() inicializa la estructura de datos Stack con memoria dinamica,
 * declara top en NULL inicialmente
 * 
 * @return Stack* stack: Stack creado
 */
Stack* initStack();


/*
 * push() agrega un nuevo nodo en la posicion top del stack
 * 
 * @param1 Stack* stack: Puntero al struct Stack
 * @param2 int data: Data que se desea agregar al nodo nuevo
 */
void push(Stack* stack, int data);


/*
 * pop() elimina el nodo ubicado en el top del stack
 * 
 * @param1 Stack* stack: Puntero al stack utilizado
 * @return int datoEliminado: Data eliminada del nodo top del stack
 *         / -1 en caso de error
 */
int pop(Stack* stack);


/*
 * top() devuelve el data del nodo top del stack
 *
 * @param1 Stack* stack: Puntero al stack empleado
 * @return int data: Data del nodo top / -1 en caso de error
 */
int top(Stack* stack);


/*
 * isEmpty() revisa si el stack esta vacio
 * 
 * @param1 Stack* stack: Puntero al stack
 * @return int estaVacio: Vacio: 1 | Error: -1 | +1 nodos: 0
 */
int isEmpty(Stack* stack);


/*
 * printStack() imprime el stack completo nodo por nodo
 * 
 * @param1 Stack* stack: Stack empleado
 */
void printStack(Stack* stack);


/*
 * freeStack() libera la memoria reservada para formar el stack
 * por medio de free()
 * 
 * @param1 Stack* stack: Stack utilizado
 */
void freeStack(Stack* stack);

#endif /* STACK_H */