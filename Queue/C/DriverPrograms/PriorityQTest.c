/*
Date : 27-6-2021
Aim  : priority q test
*/
#include <stdio.h>
#include "../PriorityQueue/PriorityQueue.h"

void main()
{
    PriorityQueue* q = createPriorityQueue();
    push(q, 10, 1);
    printf("Pushed 10\n");
    push(q, 20, 3);
    push(q, 30, 2);
    printf("%d\n", popHighestPriority(q));
    printf("%d\n", popHighestPriority(q));
}