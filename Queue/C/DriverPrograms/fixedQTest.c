/*
Date : 27-6-2021
Aim  : fixed queue test
*/
#include <stdio.h>
#include "../FixedQueue/Queue.h"

void printQueue(Queue* queue)
{
    for (int i = 0; i <= queue->rear; i++)
    {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

void main()
{
    Queue* q = createQueue(5);
    push(q, 1);
    printf("Pushed %d\n", rear(q));
    printQueue(q);
    push(q, 2);
    printf("Pushed %d\n", rear(q));
    printQueue(q);
    push(q, 3);
    printf("Pushed %d\n", rear(q));
    printQueue(q);
    push(q, 4);
    printf("Pushed %d\n", rear(q));
    printQueue(q);
    push(q, 5);
    printf("Pushed %d\n", rear(q));
    printQueue(q);
    push(q, 6);
    printf("Pushed %d\n", rear(q));
    printQueue(q);
    printf("Popped %d\n", pop(q));
    printQueue(q);
    printf("Popped %d\n", pop(q));
    printQueue(q);
    printf("Popped %d\n", pop(q));
    printQueue(q);
    printf("Popped %d\n", pop(q));
    printQueue(q);
    
}