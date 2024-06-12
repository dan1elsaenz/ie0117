#ifndef STACK_H

#define STACK_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Node* crearNodo(int data);

Stack* initStack();

void push(Stack* stack, int data);

int pop(Stack* stack);

int top(Stack* stack);

int isEmpty(Stack* stack);

void freeStack(Stack* stack);

#endif /* STACK_H */