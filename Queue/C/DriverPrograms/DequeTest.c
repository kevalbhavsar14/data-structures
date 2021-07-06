/*
Date : 27-6-2021
Aim  : double ended queue test
*/
#include <stdio.h>
#include "../DoubleEndedQueue/Deque.h"

void main()
{
    Deque* q = createDeque();
    pushFront(q, 1);
    printf("Pushed %d at front\n", front(q));
    pushRear(q, 2);
    printf("Pushed %d at rear\n", rear(q));
    pushRear(q, 3);
    printf("Pushed %d at rear\n", rear(q));
    
    printf("Popped %d\n", popRear(q));
    printf("Popped %d\n", popFront(q));
    printf("Popped %d\n", popRear(q));
    printf("Popped %d\n", popRear(q));
    
}