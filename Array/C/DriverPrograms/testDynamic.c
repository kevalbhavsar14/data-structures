#include <stdio.h>
#include "../DynamicArray/DynamicArray.h"

void main()
{
    DynamicArray* array = createArray(1);

    printf("Size : %d\n", array->size);
    for (int i = 0; i < 5; i++)
    {
        insertFirst(array, i);
    }
    printArray(array);
    printf("Length : %d\n", length(array));
    printf("Size : %d\n", array->size);
    insertLast(array, 6);
    printf("Length : %d\n", length(array));
    printf("Size : %d\n", array->size);
}