#include <stdio.h>
#include "../StaticArray/StaticArray.h"

void main()
{
    StaticArray* array = createArray(5);

    printf("Length : %d\n", length(array));

    setFirst(array, 6);
    setLast(array, 7);
    setAtIndex(array, 8, 2);
    printArray(array);

    printf("search index : %d\n", search(array, 10));


    printf("Length : %d\n", length(array));

}