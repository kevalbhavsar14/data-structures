/*
Date : 2-7-2021
Aim  : binary search tree
*/
#include <stdio.h>
#include "../BinarySearchTree/BinarySearchTree.h"

void main()
{
    // int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    int pre[6] = {7, 3, 1, 5, 9, 11};

    BinarySearchTree* tree1 = createBinarySearchTreePre(pre, 6);
    // BinarySearchTree* tree2 = createBinarySearchTreeArr(arr, 7);
    BinarySearchTree* tree3 = createEmptyTree();

    insert(tree3, 6);
    insert(tree3, 3);
    insert(tree3, 7);
    insert(tree3, 4);
    insert(tree3, 1);
    insert(tree3, 2);
    insert(tree3, 10);
    insert(tree3, 8);
    insert(tree3, 9);
    insert(tree3, 5);

    printTree2D(tree3);
    printTreeInOrder(tree3);
    printf("-------------------------------------------\n");

    delete(tree3, 8);
    printTreeInOrder(tree3);

    printTree2D(tree3);


    // printTree2D(tree1);
    // printTreeInOrder(tree1);
    // printTreePreOrder(tree1);
    // printTreePostOrder(tree1);
    // insert(tree1, 8);
    // printTree2D(tree1);
    // printTreeInOrder(tree1);
    // printTreePreOrder(tree1);
    // printTreePostOrder(tree1);
    // printTree2D(tree2);
    // printTreeInOrder(tree2);
    // printTreePreOrder(tree2);
    // printTreePostOrder(tree2);
    // Node* search = searchTree(tree1, 3);
    // if (search)
    // {
    //     printf("%d", search->data);
    // }
}