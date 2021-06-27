/*
Date : 27-6-2021
Data structure: fixwd size stack
*/
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

Stack* createStack(int size)
{
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->arr = (int*)malloc(size * sizeof(int));
    newStack->top = -1;
    newStack->size = size;
    return newStack;
}

int push(Stack* stack, int value)
{
    if (stack->top == stack->size - 1)
    {
        printf("Error: stack is full\n");
        return 0;
    }
    stack->arr[++(stack->top)] = value;
    return 1;
}

int pop(Stack* stack)
{
    if (stack->top == -1)
    {
        printf("Error: stack is empty\n");
        return 0;
    }
    return (stack->arr[(stack->top)--]);
}

int top(Stack* stack)
{
    if (stack->top == -1)
    {
        printf("Error: stack is empty");
        return 0;
    }
    return (stack->arr[(stack->top)]);
}