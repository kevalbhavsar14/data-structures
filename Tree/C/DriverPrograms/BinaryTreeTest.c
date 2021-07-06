/*
Date : 28-6-2021
Aim  : binary tree test
*/
#include <stdio.h>
#include "../BinaryTree/BinaryTree.h"

void main()
{
    int arr1[12] = {1, 2, 3, -1, -1, 4, 5, -1, -1, -1, -1, 6};
    int arr2[7] = {1, 2, 3, 4, 5, 6, 7};
    int arr3[14] = {1, 2, 3, -1, 4, 5, 6, -1, -1, -1, -1, -1, -1, 7};

    int arr6[] = {1, -1, 2, -1, -1, 3, -1, -1, -1, -1, -1, -1, 4};

    int in4[4] = {4, 3, 2, 1};
    int pre4[4] = {1, 2, 3, 4};
    int in5[4] = {1, 2, 3, 4};
    int pre5[4] = {1, 2, 3, 4};
    int in6[4] = {1, 3, 4, 2};
    int pre6[4] = {1, 2, 3, 4};

    BinaryTree* tree1 = createBinaryTreeArr(arr1, 12);
    BinaryTree* tree2 = createBinaryTreeArr(arr2, 7);
    BinaryTree* tree3 = createBinaryTreeArr(arr3, 14);
    BinaryTree* tree4 = createBinaryTreeInPre(in4, pre4, 4);
    BinaryTree* tree5 = createBinaryTreeInPre(in5, pre5, 4);
    BinaryTree* tree6 = createBinaryTreeInPre(in6, pre6, 4);
    printTreeInOrder(tree1);
    printTreeInOrderIterative(tree1);
    printTree2D(tree1);
    printTreeInOrder(tree2);
    printTreeInOrderIterative(tree2);
    printTree2D(tree2);
    printTreeInOrder(tree3);
    printTreeInOrderIterative(tree3);
    printTree2D(tree3);
    printTreeInOrder(tree4);
    printTreeInOrderIterative(tree4);
    printTree2D(tree4);
    printTreeInOrder(tree5);
    printTreeInOrderIterative(tree5);
    printTree2D(tree5);
    printTreeInOrder(tree6);
    printTreeInOrderIterative(tree6);
    printTree2D(tree6);
}