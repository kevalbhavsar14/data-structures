/*
Date : 27-6-2021
Data structure: fixed size queue
*/
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

Queue* createQueue(int size)
{
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->arr = (int*)malloc(size * sizeof(int));
    newQueue->rear = -1;
    newQueue->size = size;
    return newQueue;
}

int push(Queue* queue, int value)
{
    if (queue->rear == queue->size - 1)
    {
        printf("Error: queue is full\n");
        return 0;
    }
    queue->arr[++(queue->rear)] = value;
    return 1;
}

int pop(Queue* queue)
{
    if (queue->rear == -1)
    {
        printf("Error: queue is empty\n");
        return 0;
    }
    int value = queue->arr[0];
    for (int i = 0; i < queue->size - 1; i++)
    {
        queue->arr[i] = queue->arr[i + 1];
    }
    queue->rear--;
    return value;
}

int front(Queue* queue)
{
    if (queue->rear == -1)
    {
        printf("Error: queue is empty\n");
        return 0;
    }
    return queue->arr[0];
}

int rear(Queue* queue)
{
    if (queue->rear == -1)
    {
        printf("Error: queue is empty\n");
        return 0;
    }
    return queue->arr[queue->rear];
}
