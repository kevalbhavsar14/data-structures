/*
Date : 27-6-2021
Data structure: circular fixed size queue
*/
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

Queue* createQueue(int size)
{
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->arr = (int*)calloc(size, sizeof(int));
    newQueue->front = -1;
    newQueue->rear = -1;
    newQueue->size = size;
    return newQueue;
}

int push(Queue* queue, int value)
{
    if (queue->rear == queue->front - 1 || queue->rear - queue->front == queue->size - 1)
    {
        printf("Error: queue is full\n");
        return 0;
    }
    queue->rear = (queue->rear + 1) % queue->size;
    queue->arr[queue->rear] = value;
    if (queue->rear == 0 && queue->front == -1)
    {
        queue->front = 0;
    }
    return 1;
}

int pop(Queue* queue)
{
    if (queue->front == -1 && queue->rear == -1)
    {
        printf("Error: queue is empty\n");
        return 0;
    }
    // int value = queue->arr[0];
    // for (int i = 0; i < queue->size - 1; i++)
    // {
    //     queue->arr[i] = queue->arr[i + 1];
    // }
    // queue->rear--;
    int value = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->size;
    if (queue->front == queue->rear + 1)
    {
        queue->front = -1;
        queue->rear = -1;
    }
    return value;
}

int front(Queue* queue)
{
    if (queue->front == -1 && queue->rear == -1)
    {
        printf("Error: queue is empty\n");
        return 0;
    }
    return queue->arr[queue->front];
}

int rear(Queue* queue)
{
    if (queue->front == -1 && queue->rear == -1)
    {
        printf("Error: queue is empty\n");
        return 0;
    }
    return queue->arr[queue->rear];
}
