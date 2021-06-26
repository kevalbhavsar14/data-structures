/*
Date: 26-6-2021

data structure: Doubly linked list
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
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct List
{
    Node *head;
    Node *tail;
} List;

Node* createNode(Node *prev, int value);

List* createEmptyList();
List* createAscendingList(int size);
List* createRandomList(int size, int rangeMin, int rangeMax);
List* createListFromArray(int size, int arr[]);

int insertFirst(List *list, int value);
int insertLast(List *list, int value);
int insertAtIndex(List *list, int value, int index);
int insertAscending(List *list, int value);

int deleteFirst(List *list);
int deleteLast(List *list);
int deleteAtIndex(List *list, int index);
int deleteByValueFirstOcc(List *list, int key);
int deleteByValueLastOcc(List *list, int key);
int deleteByValueAllOcc(List *list, int key);

Node* searchList(List *list, int key);

List* reverseList(List *list);

void printList(List *list);
void printListReverse(List *list);
