/*
Date : 27-6-2021
Data structure: Double ended queue

Operations:
    push
        front
        rear
    pop
        front
        rear
    front
    rear
*/

#pragma once

typedef struct Node
{
    int value;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct Deque
{
    Node *front;
    Node *rear;
} Deque;

Deque* createDeque();

int pushFront(Deque* queue, int value);
int pushRear(Deque* queue, int value);
int popFront(Deque* queue);
int popRear(Deque* queue);
int front(Deque* queue);
int rear(Deque* queue);
