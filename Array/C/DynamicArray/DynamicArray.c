#include <stdio.h>
#include <stdlib.h>
#include "DynamicArray.h"

DynamicArray* createArray(int size)
{
    DynamicArray *a = (DynamicArray*)malloc(size * sizeof(DynamicArray));
    a->arr = (int*)malloc(size * sizeof(int));
    a->size = size;
    a->length = 0;
    return a;
}

int printArray(DynamicArray *a)
{
    if (a->length == 0)
    {
        return 0;
    }

    for (int i = 0; i < a->length; i++)
    {
        printf("%d ", a->arr[i]);
    }
    printf("\n");
    return 1;
}

int insertFirst(DynamicArray *a, int value)
{
    if (a->length == a->size)
    {
        realloc(a->arr, a->size * 2);
        a->size *= 2;
    }

    for (int i = a->length; i > 0; i--)
    {
        a->arr[i] = a->arr[i - 1];
    }
    a->arr[0] = value;
    a->length++;
    return 1;
}

int insertLast(DynamicArray *a, int value)
{
    if (a->length == a->size)
    {
        realloc(a->arr, a->size * 2);
        a->size *= 2;
    }

    a->arr[a->length] = value;
    a->length++;
    return 1;
}

int insertAtIndex(DynamicArray *a, int value, int index)
{
    if (a->length == a->size)
    {
        realloc(a->arr, a->size * 2);
        a->size *= 2;
    }
    if (index > a->length || index < 0)
    {
        printf("Error: index out of bounds.\n");
        return 0;
    }

    for (int i = a->length; i > index; i--)
    {
        a->arr[i] = a->arr[i - 1];
    }
    a->arr[index] = value;
    a->length++;
    return 1;
}

int deleteFirst(DynamicArray *a)
{
    if (a->length == 0)
    {
        printf("Error: array is empty.\n");
        return 0;
    }

    for (int i = 0; i < a->length - 1; i++)
    {
        a->arr[i] = a->arr[i+1];
    }
    a->length--;
    return 1;
}

int deleteLast(DynamicArray *a)
{
    if (a->length == 0)
    {
        printf("Error: array is empty.\n");
        return 0;
    }

    a->length--;
    return 1;
}

int deleteAtIndex(DynamicArray *a, int index)
{
    if (a->length == 0)
    {
        printf("Error: array is empty.\n");
        return 0;
    }
    if (index > a->length - 1 || index < 0)
    {
        printf("Error: index out of bounds.\n");
        return 0;
    }

    for (int i = index; i < a->length - 1; i++)
    {
        a->arr[i] = a->arr[i+1];
    }
    a->length--;
    return 1;
}

int getFirst(DynamicArray *a)
{
    if (a->length == 0)
    {
        printf("Error: array is empty.\n");
        return 0;
    }

    return a->arr[0];
}

int getLast(DynamicArray *a)
{
    if (a->length == 0)
    {
        printf("Error: array is empty.\n");
        return 0;
    }

    return a->arr[a->length - 1];
}

int getAtIndex(DynamicArray *a, int index)
{
    if (a->length == 0)
    {
        printf("Error: array is empty.\n");
        return 0;
    }
    if (index > a->length - 1 || index < 0)
    {
        printf("Error: index out of bounds.\n");
        return 0;
    }

    return a->arr[index];
}

int setFirst(DynamicArray *a, int value)
{
    if (a->length == 0)
    {
        printf("Error: array is empty.\n");
        return 0;
    }

    a->arr[0] = value;
    return 1;
}

int setLast(DynamicArray *a, int value)
{
    if (a->length == 0)
    {
        printf("Error: array is empty.\n");
        return 0;
    }

    a->arr[a->length - 1] = value;
    return 1;
}

int setAtIndex(DynamicArray *a, int value, int index)
{
    if (a->length == 0)
    {
        printf("Error: array is empty.\n");
        return 0;
    }
    if (index > a->length - 1 || index < 0)
    {
        printf("Error: index out of bounds.\n");
        return 0;
    }

    a->arr[index] = value;
    return 1;
}

int length(DynamicArray *a)
{
    return a->length;
}

int search(DynamicArray *a, int value)
{
    for (int i = 0; i < a->length; i++)
    {
        if (a->arr[i] == value)
        {
            return i;
        }
    }
    return -1;
}
