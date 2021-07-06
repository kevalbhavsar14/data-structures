/*
Date : 27-6-2021
Data structure: Double ended queue
*/
#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

Deque* createDeque()
{
    Deque* newQueue = (Deque*)malloc(sizeof(Deque));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    return newQueue;
}

int pushFront(Deque* queue, int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = queue->front;
    if (queue->front == NULL)
    {
        queue->rear = newNode;
    }
    else
    {
        queue->front->prev = newNode;
    }
    queue->front = newNode;
    return 1;
}

int pushRear(Deque* queue, int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->prev = queue->rear;
    newNode->next = NULL;
    if (queue->front == NULL)
    {
        queue->front = newNode;
    }
    else
    {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    return 1;
}

int popFront(Deque* queue)
{
    if (queue->front == NULL)
    {
        printf("Error: queue is empty\n");
        return 0;
    }
    Node* del = queue->front;
    int value = del->value;
    queue->front = queue->front->next;
    if (queue->front != NULL)
    {
        queue->front->prev = NULL;
    }
    else
    {
        queue->rear = NULL;
    }
    free(del);
    return value;
}

int popRear(Deque* queue)
{
    if (queue->front == NULL)
    {
        printf("Error: queue is empty\n");
        return 0;
    }
    Node* del = queue->rear;
    int value = del->value;
    queue->rear = queue->rear->prev;
    if (queue->rear != NULL)
    {
        queue->rear->next = NULL;
    }
    else
    {
        queue->front = NULL;
    }
    free(del);
    return value;
}

int front(Deque* queue)
{
    if (queue->front == NULL)
    {
        printf("Error: queue is empty\n");
        return 0;
    }
    return queue->front->value;
}

int rear(Deque* queue)
{
    if (queue->front == NULL)
    {
        printf("Error: queue is empty\n");
        return 0;
    }
    return queue->rear->value;
}
