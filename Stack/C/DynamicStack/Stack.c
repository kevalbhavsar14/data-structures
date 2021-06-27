/*
Date : 27-6-2021
Data structure: dynamic stack
*/
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

Stack* createStack()
{
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->top = NULL;
    return newStack;
}

int push(Stack* stack, int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = stack->top;
    stack->top = newNode;
    return 1;
}

int pop(Stack* stack)
{
    if (stack->top == NULL)
    {
        printf("Error: stack is empty\n");
        return 0;
    }
    Node* del = stack->top;
    int value;
    stack->top = stack->top->next;
    value = del->value;
    free(del);
    return value;
}

int top(Stack* stack)
{
    if (stack->top == NULL)
    {
        printf("Error: stack is empty\n");
        return 0;
    }
    return stack->top->value;
}