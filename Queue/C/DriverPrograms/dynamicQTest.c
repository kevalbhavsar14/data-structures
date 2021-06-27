/*
Date : 27-6-2021
Aim  : dynamic queue test
*/
#include <stdio.h>
#include "../DynamicQueue/Queue.h"

void main()
{
    Queue* q = createQueue();
    push(q, 1);
    printf("Pushed %d\n", rear(q));
    push(q, 2);
    printf("Pushed %d\n", rear(q));
    push(q, 3);
    printf("Pushed %d\n", rear(q));
    printf("Popped %d\n", pop(q));
    printf("Popped %d\n", pop(q));
    printf("Popped %d\n", pop(q));
    printf("Popped %d\n", pop(q));
}