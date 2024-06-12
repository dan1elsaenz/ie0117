#include "stack.h"
#include <stdio.h>

int main() {
    Stack* stack = initStack();

    printf("%d\n", isEmpty(stack));

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);

    int popped = pop(stack);

    printf("%d\n", popped);

    printf("%d\n", isEmpty(stack));

    freeStack(stack);


    return 0;
}