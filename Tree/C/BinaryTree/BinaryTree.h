/*
Date: 28-6-2021
Data structures: Binary Tree
*/

#pragma once

typedef struct Node
{
    int data;
    struct Node* left, * right;
} Node;

typedef struct BinaryTree
{
    Node* root;
} BinaryTree;

BinaryTree* createBinaryTreeArr(int arr[], int arrLength);
BinaryTree* createBinaryTreeInPre(int inOreder[], int preOrder[], int arrLength);
BinaryTree* createBinaryTreeInPost(int inOreder[], int postOrder[], int arrLength);

void printTreeInOrder(BinaryTree* tree);
void printTreePreOrder(BinaryTree* tree);
void printTreePostOrder(BinaryTree* tree);

void printTreeInOrderIterative(BinaryTree* tree);
void printTreePreOrderIterative(BinaryTree* tree);

void printTreeBreadthFirst(BinaryTree* tree);

void printTree2D(BinaryTree* tree);
