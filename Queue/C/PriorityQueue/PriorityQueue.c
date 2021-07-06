/*
Date : 27-6-2021
Data structure: fixed size queue
*/
#include <stdio.h>
#include <stdlib.h>
#include "PriorityQueue.h"

PriorityQueue* createPriorityQueue()
{
    PriorityQueue* newQueue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    return newQueue;
}

int push(PriorityQueue* queue, int value, int priority)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->priority = priority;
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

int popHighestPriority(PriorityQueue* queue)
{
    Node* temp = queue->front;
    Node* delPrev, * del;
    int highest = 0;
    while (temp->next != NULL)
    {
        if (temp->next->priority > highest)
        {
            highest = temp->next->priority;
            delPrev = temp;
        }
        temp = temp->next;
    }
    del = delPrev->next;
    int value = del->value;
    delPrev->next = delPrev->next->next;
    free(del);
    return value;
}

int getHighestPriority(PriorityQueue* queue)
{
    Node* temp = queue->front;
    Node* highestNode;
    int highest = 0;
    while (temp->next != NULL)
    {
        if (temp->priority > highest)
        {
            highest = temp->priority;
            highestNode = temp;
        }
        temp = temp->next;
    }
    return highestNode->value;
}
