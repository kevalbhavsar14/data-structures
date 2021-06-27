/*
Date : 27-6-2021
Aim  : circular fixed queue test
*/
#include <stdio.h>
#include "../CircularQueue/Queue.h"

void printQueue(Queue* queue)
{
    for (int i = 0; i < queue->size; i++)
    {
        printf("%-3d", queue->arr[i]);
    }
    printf("\n");
    for (int i = 0; i < queue->size; i++)
    {
        if (i == queue->front && i == queue->rear)
        {
            printf("fr ");
        }
        else if (i == queue->front)
        {
            printf("f  ");
        }
        else if (i == queue->rear)
        {
            printf("r  ");
        }
        
        else
        {
            printf("   ");
        }
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
    push(q, 6);
    printf("Pushed %d\n", rear(q));
    printQueue(q);
    push(q, 7);
    printf("Pushed %d\n", rear(q));
    printQueue(q);
    push(q, 8);
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
    printf("Popped %d\n", pop(q));
    printQueue(q);
    push(q, 1);
    printf("Pushed %d\n", rear(q));
    printQueue(q);
}