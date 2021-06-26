/*
Date: 25-6-2021

data structure: linked list
contains:
    Node data type for list
    functions:
        Craete
        Insert:
            First
            Last
            Index
            Acsending
        Delete:
            First
            Last
            Index
            Value
        Print
        Length
*/

#pragma once

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef struct List
{
    Node *head;
} List;

Node* createNode(int value);

List* createEmptyList();
List* createAscendingList(int size);
List* createRandomList(int size, int rangeMin, int rangeMax);
List* createListFromArray(int size, int arr[]);

int insertFirst(List *_list, int value);
int insertLast(List *_list, int value);
int insertAtIndex(List *_list, int value, int index);
int insertAscending(List *_list, int value);

int deleteFirst(List *_list);
int deleteLast(List *_list);
int deleteAtIndex(List *_list, int index);
int deleteByValueFirstOcc(List *_list, int key);
int deleteByValueLastOcc(List *_list, int key);
int deleteByValueAllOcc(List *_list, int key);

Node* searchList(List *_list, int key);

void printList(List *_list);
