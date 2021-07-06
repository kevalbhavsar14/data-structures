/*
Date: 2-7-2021
Data structures: Binary Search Tree
*/

#pragma once

typedef struct Node
{
    int data;
    struct Node* left, * right;
} Node;

typedef struct BinarySearchTree
{
    Node* root;
} BinarySearchTree;

// BinarySearchTree* createBinarySearchTreeArr(int arr[], int arrLength);
// BinarySearchTree* createBinarySearchTreeInPre(int inOreder[], int preOrder[], int arrLength);
// BinarySearchTree* createBinarySearchTreeInPost(int inOreder[], int postOrder[], int arrLength);

BinarySearchTree* createEmptyTree();
BinarySearchTree* createBinarySearchTreeArr(int arr[], int arrLength);
BinarySearchTree* createBinarySearchTreePre(int preOrder[], int arrLength);

int insert(BinarySearchTree* tree, int data);
int delete(BinarySearchTree* tree, int value);

Node* searchTree(BinarySearchTree* tree, int key);

void printTreeInOrder(BinarySearchTree* tree);
void printTreePreOrder(BinarySearchTree* tree);
void printTreePostOrder(BinarySearchTree* tree);

void printTreeInOrderIterative(BinarySearchTree* tree);
void printTreePreOrderIterative(BinarySearchTree* tree);

void printTreeBreadthFirst(BinarySearchTree* tree);

void printTree2D(BinarySearchTree* tree);
