#include <stdio.h>
#include <stdlib.h>
#include "List.h"

Node* createNode(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

List* createEmptyList()
{
    List* newList = (List*)malloc(sizeof(List));
    newList->head = NULL;
    return newList;
}

List* createAscendingList(int size)
{
    List* newList = (List*)malloc(sizeof(List));
    Node* temp;
    newList->head = createNode(1);
    temp = newList->head;
    for (int i = 1; i < size; i++)
    {
        temp->next = createNode(i + 1);
        temp = temp->next;
    }
    return newList;
}

List* createRandomList(int size, int rangeMin, int rangeMax)
{
    List* newList = (List*)malloc(sizeof(List));
    Node* temp;
    int randValue = rangeMin + rand() % (rangeMax - rangeMin + 1);
    newList->head = createNode(randValue);
    temp = newList->head;
    for (int i = 1; i < size; i++)
    {
        randValue = rangeMin + rand() % (rangeMax - rangeMin + 1);
        temp->next = createNode(randValue);
        temp = temp->next;
    }
    return newList;
}

List* createListFromArray(int size, int arr[])
{
    List* newList = (List*)malloc(sizeof(List));
    Node* temp;
    newList->head = createNode(arr[0]);
    temp = newList->head;
    for (int i = 1; i < size; i++)
    {
        temp->next = createNode(arr[i]);
        temp = temp->next;
    }
    return newList;
}

int insertFirst(List *_list, int value)
{
    Node* newNode = createNode(value);
    newNode->next = _list->head;
    _list->head = newNode;
    return 1;
}

int insertLast(List *_list, int value)
{
    Node* newNode = createNode(value);
    Node* temp = _list->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return 1;
}

int insertAtIndex(List *_list, int value, int index)
{
    Node* newNode = createNode(value);
    Node* temp = _list->head;
    int found = 0;
    if (index == 0)
    {
        insertFirst(_list, value);
        return 1;
    }
    for (int i = 0; temp != NULL; i++)
    {
        if (i == index - 1)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if (!found)
    {
        printf("Error: Index out of bounds\n");
        return 0;
    }
    return 1;
}

int insertAscending(List *_list, int value)
{
    Node* newNode = createNode(value);
    Node* temp = _list->head;
    int current = 0;
    while (temp->next != NULL)
    {
        current++;
        if (temp->next->value > value)
        {
            break;
        }
        temp = temp->next;
    }
    if (current == 1)
    {
        insertFirst(_list, value);
        return 1;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return 1;
}

int deleteFirst(List *_list)
{
    if (_list->head == NULL)
    {
        printf("Error: list is empty\n");
        return 0;
    }
    Node* del = _list->head;
    int value;
    _list->head = _list->head->next;
    value = del->value;
    free(del);
    return value;
}

int deleteLast(List *_list)
{
    if (_list->head == NULL)
    {
        printf("Error: list is empty\n");
        return 0;
    }
    Node* temp = _list->head;
    Node* del;
    int value;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    del = temp->next;
    temp->next = NULL;
    value = del->value;
    free(del);
    return value;
}

int deleteAtIndex(List *_list, int index)
{
    if (_list->head == NULL)
    {
        printf("Error: list is empty\n");
        return 0;
    }
    if (index == 0)
    {
        deleteFirst(_list);
        return 1;
    }
    Node* temp = _list->head;
    Node* del;
    int value;
    for (int i = 0; temp != NULL; i++)
    {
        if (i == index - 1)
        {
            del = temp->next;
            temp->next = temp->next->next;
            value = del->value;
            free(del);
            return value;
        }
        temp = temp->next;
    }
}

int deleteByValueFirstOcc(List *_list, int key)
{
    Node* temp = _list->head;
    Node* del;
    while (temp->next != NULL)
    {
        if (temp->next->value == key)
        {
            del = temp->next;
            temp->next = temp->next->next;
            free(del);
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int deleteByValueLastOcc(List *_list, int key)
{
    Node* temp = _list->head;
    Node* delPrev, * del;
    int found = 0;
    while (temp->next != NULL)
    {
        if (temp->next->value == key)
        {
            delPrev = temp;
            found = 1;
        }
        temp = temp->next;
    }
    if (!found)
    {
        return 0;
    }
    del = delPrev->next;
    delPrev->next = delPrev->next->next;
    free(del);
    return 1;
}

int deleteByValueAllOcc(List *_list, int key)
{
    Node* temp = _list->head;
    Node* del;
    int found = 0;
    while (temp->next != NULL)
    {
        if (temp->next->value == key)
        {
            del = temp->next;
            temp->next = temp->next->next;
            free(del);
            found = 1;
            continue;
        }
        temp = temp->next;
    }
    if (!found)
    {
        return 0;
    }
    return 1;
}

Node* searchList(List *_list, int key)
{
    Node* temp = _list->head;
    while (temp != NULL)
    {
        if (temp->value == key)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void printList(List *_list)
{
    Node* temp = _list->head;
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}
