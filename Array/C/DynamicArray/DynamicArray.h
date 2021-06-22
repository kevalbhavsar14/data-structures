/*
dyanamic array custom data structure
functions header

insert -> first, last, index
delete -> first, last, index
get -> first last index
set -> first last index
length
*/

#pragma once

typedef struct
{
    int *arr;
    int size;
    int length;
} DynamicArray;

DynamicArray* createArray(int size);

int printArray(DynamicArray *a);

int insertFirst(DynamicArray *a, int value);
int insertLast(DynamicArray *a, int value);
int insertAtIndex(DynamicArray *a, int value, int index);

int deleteFirst(DynamicArray *a);
int deleteLast(DynamicArray *a);
int deleteAtIndex(DynamicArray *a, int index);

int getFirst(DynamicArray *a);
int getLast(DynamicArray *a);
int getAtIndex(DynamicArray *a, int index);

int setFirst(DynamicArray *a, int value);
int setLast(DynamicArray *a, int value);
int setAtIndex(DynamicArray *a, int value, int index);

int length(DynamicArray *a);

int search(DynamicArray *a, int value);
