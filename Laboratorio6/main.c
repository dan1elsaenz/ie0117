#include "stack.h"
#include <stdio.h>

int main() {
    Stack* stack = initStack();

    printf("%d\n", isEmpty(stack));

    push(stack, 1);

    printStack(stack);

    push(stack, 2);
    
    printStack(stack);


    push(stack, 3);
    printStack(stack);
    push(stack, 4);
    printStack(stack);

    int popped = pop(stack);

    printf("%d\n", popped);

    printStack(stack);

    printf("%d\n", isEmpty(stack));

    freeStack(stack);


    return 0;
}