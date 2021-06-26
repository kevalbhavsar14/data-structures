#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

Node* createNode(Node *prev, int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->prev = prev;
    newNode->next = NULL;
    return newNode;
}

List* createEmptyList()
{
    List* newList = (List*)malloc(sizeof(List));
    newList->head = NULL;
    newList->tail = NULL;
    return newList;
}

List* createAscendingList(int size)
{
    List* newList = (List*)malloc(sizeof(List));
    Node* temp;
    newList->head = createNode(NULL, 1);
    temp = newList->head;
    for (int i = 1; i < size; i++)
    {
        temp->next = createNode(temp, i + 1);
        temp = temp->next;
    }
    newList->tail = temp;
    return newList;
}

List* createRandomList(int size, int rangeMin, int rangeMax)
{
    List* newList = (List*)malloc(sizeof(List));
    Node* temp;
    int randValue = rangeMin + rand() % (rangeMax - rangeMin + 1);
    newList->head = createNode(NULL, randValue);
    temp = newList->head;
    for (int i = 1; i < size; i++)
    {
        randValue = rangeMin + rand() % (rangeMax - rangeMin + 1);
        temp->next = createNode(temp, randValue);
        temp = temp->next;
    }
    newList->tail = temp;
    return newList;
}

List* createListFromArray(int size, int arr[])
{
    List* newList = (List*)malloc(sizeof(List));
    Node* temp;
    newList->head = createNode(NULL, arr[0]);
    temp = newList->head;
    for (int i = 1; i < size; i++)
    {
        temp->next = createNode(temp, arr[i]);
        temp = temp->next;
    }
    newList->tail = temp;
    return newList;
}

int insertFirst(List *list, int value)
{
    Node* newNode = createNode(NULL, value);
    newNode->next = list->head;
    if (list->head == NULL)
    {
        list->tail = newNode;
    }
    else
    {
        list->head->prev = newNode;
    }
    list->head = newNode;
    return 1;
}

int insertLast(List *list, int value)
{
    Node* newNode = createNode(list->tail, value);
    if (list->head == NULL)
    {
        list->head = newNode;
    }
    else
    {
        list->tail->next = newNode;
    }
    list->tail = newNode;
    return 1;
}

int insertAtIndex(List *list, int value, int index)
{
    Node* temp = list->head;
    int found = 0;
    if (index == 0)
    {
        insertFirst(list, value);
        return 1;
    }
    for (int i = 0; temp != NULL; i++)
    {
        if (i == index - 1)
        {
            Node* newNode = createNode(temp, value);
            newNode->next = temp->next;
            if (temp->next == NULL)
            {
                list->tail = newNode;
            }
            else
            {
                temp->next->prev = newNode;
            }
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

int insertAscending(List *list, int value)
{
    Node* temp = list->head;
    if (temp->value > value)
    {
        insertFirst(list, value);
        return 1;
    }
    while (temp->next != NULL)
    {
        if (temp->next->value > value)
        {
            break;
        }
        temp = temp->next;
    }
    Node* newNode = createNode(temp, value);
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    return 1;
}

int deleteFirst(List *list)
{
    if (list->head == NULL)
    {
        printf("Error: list is empty\n");
        return 0;
    }
    Node* del = list->head;
    int value;
    list->head = list->head->next;
    list->head->prev = NULL;
    value = del->value;
    free(del);
    return value;
}

int deleteLast(List *list)
{
    if (list->head == NULL)
    {
        printf("Error: list is empty\n");
        return 0;
    }
    Node* del = list->tail;
    int value;
    list->tail = list->tail->prev;
    list->tail->next = NULL;
    value = del->value;
    free(del);
    return value;
}

int deleteAtIndex(List *list, int index)
{
    if (list->head == NULL)
    {
        printf("Error: list is empty\n");
        return 0;
    }
    if (index == 0)
    {
        deleteFirst(list);
        return 1;
    }
    Node* temp = list->head;
    Node* del;
    int value;
    for (int i = 0; temp->next != NULL; i++)
    {
        if (i == index - 1)
        {
            del = temp->next;
            temp->next = temp->next->next;
            if (temp->next == NULL)
            {
                list->tail = temp;
            }
            else
            {
                temp->next->prev = temp;
            }
            value = del->value;
            free(del);
            return value;
        }
        temp = temp->next;
    }
    printf("Error: Index out of bounds\n");
    return 0;
}

int deleteByValueFirstOcc(List *list, int key)
{
    Node* temp = list->head;
    Node* del;
    while (temp->next != NULL)
    {
        if (temp->next->value == key)
        {
            del = temp->next;
            temp->next = temp->next->next;
            if (temp->next == NULL)
            {
                list->tail = temp;
            }
            else
            {
                temp->next->prev = temp;
            }
            free(del);
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int deleteByValueLastOcc(List *list, int key)
{
    Node* temp = list->head;
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
    if (temp->next == NULL)
    {
        list->tail = delPrev;
    }
    else
    {
        delPrev->next->prev = delPrev;
    }
    free(del);
    return 1;
}

int deleteByValueAllOcc(List *list, int key)
{
    Node* temp = list->head;
    Node* del;
    int found = 0;
    while (temp->next != NULL)
    {
        if (temp->next->value == key)
        {
            del = temp->next;
            temp->next = temp->next->next;
            if (temp->next == NULL)
            {
                list->tail = temp;
            }
            else
            {
                temp->next->prev = temp;
            }
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

Node* searchList(List *list, int key)
{
    Node* temp = list->head;
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

List* reverseList(List *list)
{
    List* rev = createEmptyList();
    Node* temp = list->head;
    while (temp != NULL)
    {
        insertFirst(rev, temp->value);
        temp = temp->next;
    }
    return rev;
}

void printList(List *list)
{
    Node* temp = list->head;
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void printListReverse(List *list)
{
    Node* temp = list->tail;
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->prev;
    }
    printf("\n");
}
