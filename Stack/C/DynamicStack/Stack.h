/*
Date : 27-6-2021
Data structure: dynamic stack

Operations:
    push
    pop
    top
*/

#pragma once

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef struct Stack
{
    Node *top;
} Stack;

Stack* createStack();

int push(Stack* stack, int value);
int pop(Stack* stack);
int top(Stack* stack);
