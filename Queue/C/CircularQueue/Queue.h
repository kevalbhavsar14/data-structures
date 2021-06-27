/*
Date : 27-6-2021
Data structure: circular fixed size queue

Operations:
    push
    pop
    front
    rear
*/

#pragma once

typedef struct Queue {
    int *arr;
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue(int size);

int push(Queue* queue, int value);
int pop(Queue* queue);
int front(Queue* queue);
int rear(Queue* queue);
