#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

Queue* createQueue()
{
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    return newQueue;
}

int push(Queue* queue, int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    if (queue->rear != NULL)
    {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    if (queue->front == NULL)
    {
        queue->front = newNode;
    }
    return 1;
}

int pop(Queue* queue)
{
    if (queue->front == NULL)
    {
        printf("Error: queue is empty\n");
        return 0;
    }
    Node* del = queue->front;
    int value = del->value;
    queue->front = queue->front->next;
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    free(del);
    return value;
}

int front(Queue* queue)
{
    if (queue->front == NULL)
    {
        printf("Error: queue is empty\n");
        return 0;
    }
    return queue->front->value;
}

int rear(Queue* queue)
{
    if (queue->front == NULL)
    {
        printf("Error: queue is empty\n");
        return 0;
    }
    return queue->rear->value;
}
