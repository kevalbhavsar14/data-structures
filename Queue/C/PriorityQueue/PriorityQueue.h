/*
Date : 27-6-2021
Data structure: fixed size queue

Operations:
    push
    popHighestPriority
    getHighestPriority
*/

#pragma once

typedef struct Node
{
    int value;
    int priority;
    struct Node* next;
} Node;

typedef struct PriorityQueue
{
    Node* front;
    Node* rear;
} PriorityQueue;

PriorityQueue* createPriorityQueue();

int push(PriorityQueue* queue, int value, int priority);
int popHighestPriority(PriorityQueue* queue);
int getHighestPriority(PriorityQueue* queue);
