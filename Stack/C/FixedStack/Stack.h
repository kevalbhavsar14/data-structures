/*
Date : 27-6-2021
Data structure: fixed size stack

Operations:
    push
    pop
    top
*/

#pragma once

typedef struct Stack {
    int *arr;
    int top;
    int size;
} Stack;

Stack* createStack(int size);

int push(Stack* stack, int value);
int pop(Stack* stack);
int top(Stack* stack);
