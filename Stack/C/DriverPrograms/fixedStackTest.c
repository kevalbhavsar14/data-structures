/*
Date : 27-6-2021
Aim  : fixed stack test
*/
#include <stdio.h>
#include "../FixedStack/Stack.h"

void main()
{
    Stack* stack = createStack(5);
    push(stack, 1);
    printf("Pushed %d\n", top(stack));
    push(stack, 2);
    printf("Pushed %d\n", top(stack));
    push(stack, 3);
    printf("Pushed %d\n", top(stack));
    push(stack, 4);
    printf("Pushed %d\n", top(stack));
    push(stack, 5);
    printf("Pushed %d\n", top(stack));
    push(stack, 6);
    printf("Pushed %d\n", top(stack));
    
}