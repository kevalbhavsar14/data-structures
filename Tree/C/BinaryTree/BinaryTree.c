/*
Date: 28-6-2021
Data structures: Binary Tree
*/
#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

#define COUNT 10

typedef struct qNode
{
    Node* value;
    struct qNode *next;
} qNode;

typedef struct Queue
{
    qNode *front;
    qNode *rear;
} Queue;

Queue* createQueue();

int push(Queue* queue, Node* value);
Node* pop(Queue* queue);

Queue* createQueue()
{
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    return newQueue;
}

int push(Queue* queue, Node* value)
{
    if (value == NULL)
    {
        return 0;
    }
    
    qNode* newNode = (qNode*)malloc(sizeof(qNode));
    newNode->value = value;
    newNode->next = NULL;
    if (queue->rear != NULL)
    {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    if (queue->front == NULL)
    {
        queue->front = newNode;
    }
    return 1;
}

Node* pop(Queue* queue)
{
    if (queue->front == NULL)
    {
        printf("Error: queue is empty\n");
        return 0;
    }
    qNode* del = queue->front;
    Node* value = del->value;
    queue->front = queue->front->next;
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    free(del);
    return value;
}

typedef struct sNode
{
    Node* value;
    struct sNode *next;
} sNode;

typedef struct Stack
{
    sNode *top;
} Stack;

Stack* createStack();

int sPush(Stack* stack, Node* value);
Node* sPop(Stack* stack);
Node* top(Stack* stack);

Stack* createStack()
{
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->top = NULL;
    return newStack;
}

int sPush(Stack* stack, Node* value)
{
    if (value == NULL)
    {
        return 0;
    }
    sNode* newNode = (sNode*)malloc(sizeof(sNode));
    newNode->value = value;
    newNode->next = stack->top;
    stack->top = newNode;
    return 1;
}

Node* sPop(Stack* stack)
{
    if (stack->top == NULL)
    {
        printf("Error: stack is empty\n");
        return 0;
    }
    sNode* del = stack->top;
    Node* value;
    stack->top = stack->top->next;
    value = del->value;
    free(del);
    return value;
}

Node* top(Stack* stack)
{
    if (stack->top == NULL)
    {
        printf("Error: stack is empty\n");
        return 0;
    }
    return stack->top->value;
}


Node* createNode(int data);
Node* createBinaryTreeArrRec(int arr[], int arrLength, int index);
Node* createBinaryTreeInPreRec(int inOreder[], int preOrder[], int arrLength);
Node* createBinaryTreeInPostRec(int inOreder[], int postOrder[], int arrLength);
void printTreeInOrderRec(Node* root);
void printTreePreOrderRec(Node* root);
void printTreePostOrderRec(Node* root);
void printTree2DUtil(Node* root, int space);

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BinaryTree* createBinaryTreeArr(int arr[], int arrLength)
{
    if (!arr)
    {
        return NULL;
    }
    BinaryTree* tree = (BinaryTree*)malloc(sizeof(BinaryTree));
    tree->root = createBinaryTreeArrRec(arr, arrLength, 0);
}

Node* createBinaryTreeArrRec(int arr[], int arrLength, int index)
{
    if (arr[index] == -1 || index >= arrLength)
    {
        return NULL;
    }
    Node* newNode = createNode(arr[index]);
    newNode->left = createBinaryTreeArrRec(arr, arrLength, 2 * index + 1);
    newNode->right = createBinaryTreeArrRec(arr, arrLength, 2 * index + 2);
    return newNode;
}

BinaryTree* createBinaryTreeInPre(int inOreder[], int preOrder[], int arrLength)
{
    BinaryTree* tree = (BinaryTree*)malloc(sizeof(BinaryTree));
    tree->root = createBinaryTreeInPreRec(inOreder, preOrder, arrLength);
    return tree;
}

Node* createBinaryTreeInPreRec(int inOreder[], int preOrder[], int arrLength)
{
    if (arrLength == 0)
    {
        return NULL;
    }
    
    Node* root = createNode(preOrder[0]);
    int rootIndex, leftLength, rightLength;
    for (int i = 0; i < arrLength; i++)
    {
        if (inOreder[i] == root->data)
        {
            rootIndex = i;
            break;
        }
    }
    leftLength = rootIndex;
    rightLength = arrLength - (rootIndex + 1);
    
    int* leftIn = (int*)malloc(leftLength * sizeof(int));
    int* leftPre = (int*)malloc(leftLength * sizeof(int));
    
    int* rightIn = (int*)malloc(rightLength * sizeof(int));
    int* rightPre = (int*)malloc(rightLength * sizeof(int));

    for (int i = 0; i < leftLength; i++)
    {
        leftIn[i] = inOreder[i];
        leftPre[i] = preOrder[i + 1];
    }
    for (int i = 0; i < rightLength; i++)
    {
        rightIn[i] = inOreder[i + rootIndex + 1];
        rightPre[i] = preOrder[i + rootIndex + 1];
    }
    
    root->left = createBinaryTreeInPreRec(leftIn, leftPre, leftLength);
    root->right = createBinaryTreeInPreRec(rightIn, rightPre, rightLength);

    free(leftIn);
    free(leftPre);
    free(rightIn);
    free(rightPre);

    return root;
}

BinaryTree* createBinaryTreeInPost(int inOreder[], int postOrder[], int arrLength)
{
    BinaryTree* tree = (BinaryTree*)malloc(sizeof(BinaryTree));
    tree->root = createBinaryTreeInPostRec(inOreder, postOrder, arrLength);
    return tree;
}

Node* createBinaryTreeInPostRec(int inOreder[], int postOrder[], int arrLength)
{
    if (arrLength == 0)
    {
        return NULL;
    }
    
    Node* root = createNode(postOrder[arrLength - 1]);
    int rootIndex, leftLength, rightLength;
    for (int i = 0; i < arrLength; i++)
    {
        if (inOreder[i] == root->data)
        {
            rootIndex = i;
            break;
        }
    }
    leftLength = rootIndex;
    rightLength = arrLength - (rootIndex + 1);
    
    int* leftIn = (int*)malloc(leftLength * sizeof(int));
    int* leftPost = (int*)malloc(leftLength * sizeof(int));
    
    int* rightIn = (int*)malloc(rightLength * sizeof(int));
    int* rightPost = (int*)malloc(rightLength * sizeof(int));

    for (int i = 0; i < leftLength; i++)
    {
        leftIn[i] = inOreder[i];
        leftPost[i] = postOrder[i];
    }
    for (int i = 0; i < rightLength; i++)
    {
        rightIn[i] = inOreder[i + rootIndex + 1];
        rightPost[i] = postOrder[i + rootIndex];
    }
    
    root->left = createBinaryTreeInPostRec(leftIn, leftPost, leftLength);
    root->right = createBinaryTreeInPostRec(rightIn, rightPost, rightLength);

    free(leftIn);
    free(leftPost);
    free(rightIn);
    free(rightPost);

    return root;
}

void printTreeInOrder(BinaryTree* tree)
{
    printTreeInOrderRec(tree->root);
    printf("\n");
}

void printTreeInOrderRec(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    printTreeInOrderRec(root->left);
    printf("%d ", root->data);
    printTreeInOrderRec(root->right);
}

void printTreePreOrder(BinaryTree* tree)
{
    printTreePreOrderRec(tree->root);
    printf("\n");
}

void printTreePreOrderRec(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    printTreePreOrderRec(root->left);
    printTreePreOrderRec(root->right);
}

void printTreePostOrder(BinaryTree* tree)
{
    printTreePostOrderRec(tree->root);
    printf("\n");
}

void printTreePostOrderRec(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    printTreePostOrderRec(root->left);
    printTreePostOrderRec(root->right);
    printf("%d ", root->data);
}

void printTreePreOrderIterative(BinaryTree* tree)
{
    Stack* s = createStack();
    sPush(s, tree->root);

    while (s->top != NULL)
    {
        Node* currentNode = sPop(s);
        printf("%d ", currentNode->data);

        sPush(s, currentNode->right);
        sPush(s, currentNode->left);
    }
    printf("\n");
}

void printTreeInOrderIterative(BinaryTree* tree)
{
    Stack* s = createStack();
    Node* currentNode = tree->root;

    while (s->top || currentNode)
    {
        while (currentNode)
        {
            sPush(s, currentNode);
            currentNode = currentNode->left;
        }
        currentNode = sPop(s);
        printf("%d ", currentNode->data);
        currentNode = currentNode->right;
    }
    printf("\n");
}

void printTreeBreadthFirst(BinaryTree* tree)
{
    Queue* q = createQueue();
    push(q, tree->root);

    while (q->front != NULL)
    {
        Node* currentNode = pop(q);
        printf("%d ", currentNode->data);

        push(q, currentNode->left);
        push(q, currentNode->right);
    }
    printf("\n");
}

void printTree2D(BinaryTree* tree)
{
    printTree2DUtil(tree->root, 0);
    printf("\n");
}

void printTree2DUtil(Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;
  
    // Increase distance between levels
    space += COUNT;
  
    // Process right child first
    printTree2DUtil(root->right, space);
  
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
  
    // Process left child
    printTree2DUtil(root->left, space);
}
