/*
Date : 26-6-2021
Aim  : Doubly linked list test
*/
#include <stdio.h>
#include "../DoublyLinkedList/DoublyLinkedList.h"

void main()
{
    List* list = createRandomList(10, 1, 10);
    List* rev = reverseList(list);
    printList(list);
    printListReverse(list);
    printList(rev);
    printListReverse(rev);
    
}