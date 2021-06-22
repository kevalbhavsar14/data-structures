/*
static array custom data structure
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
} StaticArray;

StaticArray* createArray(int size);

int printArray(StaticArray *a);

int insertFirst(StaticArray *a, int value);
int insertLast(StaticArray *a, int value);
int insertAtIndex(StaticArray *a, int value, int index);

int deleteFirst(StaticArray *a);
int deleteLast(StaticArray *a);
int deleteAtIndex(StaticArray *a, int index);

int getFirst(StaticArray *a);
int getLast(StaticArray *a);
int getAtIndex(StaticArray *a, int index);

int setFirst(StaticArray *a, int value);
int setLast(StaticArray *a, int value);
int setAtIndex(StaticArray *a, int value, int index);

int length(StaticArray *a);

int search(StaticArray *a, int value);
