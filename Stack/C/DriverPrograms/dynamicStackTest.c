/*
Date : 27-6-2021
Aim  : dynamic stack test
*/
#include <stdio.h>
#include "../DynamicStack/Stack.h"

void main()
{
    Stack* stack = createStack();
    push(stack, 1);
    printf("Pushed %d\n", top(stack));
    push(stack, 2);
    printf("Pushed %d\n", top(stack));
    printf("Popped %d\n", pop(stack));
    printf("Popped %d\n", pop(stack));
    printf("Popped %d\n", pop(stack));
    
}