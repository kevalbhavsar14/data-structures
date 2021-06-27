/*
Date : 27-6-2021
Data structure: fixed size queue

Operations:
    push
    pop
    front
    rear
*/

#pragma once

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

Queue* createQueue();

int push(Queue* queue, int value);
int pop(Queue* queue);
int front(Queue* queue);
int rear(Queue* queue);
