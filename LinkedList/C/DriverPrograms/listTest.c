/*
Date : 25-6-2021
Aim  : list test
*/
#include <stdio.h>
#include "../SinglyLinkedList/List.h"

void main()
{
    List* l = createRandomList(10, 1, 10);
    List* rev = reverseList(l);
    printList(l);
    printList(rev);
}