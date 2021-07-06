/*
Date: 28-6-2021
Data structures: Binary Tree
*/
#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

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
Node* createBinarySearchTreeArrRec(int arr[], int start, int end);
Node* createBinarySearchTreePreRec(int preOrder[], int arrLength);
// Node* createBinarySearchTreeInPostRec(int inOreder[], int postOrder[], int arrLength);
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

BinarySearchTree* createEmptyTree()
{
    BinarySearchTree* tree = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
    tree->root = NULL;
    return tree;
}

// BinarySearchTree* createBinarySearchTreeArr(int arr[], int arrLength)
// {
//     if (!arr)
//     {
//         return NULL;
//     }
//     BinarySearchTree* tree = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
//     tree->root = createBinarySearchTreeArrRec(arr, arrLength, 0);
// }

// Node* createBinarySearchTreeArrRec(int arr[], int arrLength, int index)
// {
//     if (arr[index] == -1 || index >= arrLength)
//     {
//         return NULL;
//     }
//     Node* newNode = createNode(arr[index]);
//     newNode->left = createBinarySearchTreeArrRec(arr, arrLength, 2 * index + 1);
//     newNode->right = createBinarySearchTreeArrRec(arr, arrLength, 2 * index + 2);
//     return newNode;
// }

BinarySearchTree* createBinarySearchTreeArr(int arr[], int arrLength)
{
    BinarySearchTree* tree = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
    tree->root = createBinarySearchTreeArrRec(arr, 0, arrLength - 1);
    return tree;
}

Node* createBinarySearchTreeArrRec(int arr[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end)/2;
    Node *root = createNode(arr[mid]);
 
    root->left =  createBinarySearchTreeArrRec(arr, start, mid-1);
    root->right = createBinarySearchTreeArrRec(arr, mid+1, end);
 
    return root;
}

BinarySearchTree* createBinarySearchTreePre(int preOrder[], int arrLength)
{
    BinarySearchTree* tree = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
    tree->root = createBinarySearchTreePreRec(preOrder, arrLength);
    return tree;
}

Node* createBinarySearchTreePreRec(int preOrder[], int arrLength)
{
    if (arrLength == 0)
    {
        return NULL;
    }
    
    Node* root = createNode(preOrder[0]);
    int leftLength = 0, rightLength;
    for (int i = 1; i < arrLength; i++)
    {
        if (preOrder[i] < root->data)
        {
            leftLength++;
        }
        
    }
    rightLength = arrLength - leftLength - 1;
    
    int* leftPre = (int*)malloc(leftLength * sizeof(int));
    int* rightPre = (int*)malloc(rightLength * sizeof(int));

    for (int i = 0; i < leftLength; i++)
    {
        leftPre[i] = preOrder[i + 1];
    }
    for (int i = 0; i < rightLength; i++)
    {
        rightPre[i] = preOrder[i + leftLength + 1];
    }
    
    root->left = createBinarySearchTreePreRec(leftPre, leftLength);
    root->right = createBinarySearchTreePreRec(rightPre, rightLength);

    free(leftPre);
    free(rightPre);

    return root;
}

// BinarySearchTree* createBinarySearchTreeInPost(int inOreder[], int postOrder[], int arrLength)
// {
//     BinarySearchTree* tree = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
//     tree->root = createBinarySearchTreeInPostRec(inOreder, postOrder, arrLength);
//     return tree;
// }

// Node* createBinarySearchTreeInPostRec(int inOreder[], int postOrder[], int arrLength)
// {
//     if (arrLength == 0)
//     {
//         return NULL;
//     }
    
//     Node* root = createNode(postOrder[arrLength - 1]);
//     int rootIndex, leftLength, rightLength;
//     for (int i = 0; i < arrLength; i++)
//     {
//         if (inOreder[i] == root->data)
//         {
//             rootIndex = i;
//             break;
//         }
//     }
//     leftLength = rootIndex;
//     rightLength = arrLength - (rootIndex + 1);
    
//     int* leftIn = (int*)malloc(leftLength * sizeof(int));
//     int* leftPost = (int*)malloc(leftLength * sizeof(int));
    
//     int* rightIn = (int*)malloc(rightLength * sizeof(int));
//     int* rightPost = (int*)malloc(rightLength * sizeof(int));

//     for (int i = 0; i < leftLength; i++)
//     {
//         leftIn[i] = inOreder[i];
//         leftPost[i] = postOrder[i];
//     }
//     for (int i = 0; i < rightLength; i++)
//     {
//         rightIn[i] = inOreder[i + rootIndex + 1];
//         rightPost[i] = postOrder[i + rootIndex];
//     }
    
//     root->left = createBinarySearchTreeInPostRec(leftIn, leftPost, leftLength);
//     root->right = createBinarySearchTreeInPostRec(rightIn, rightPost, rightLength);

//     free(leftIn);
//     free(leftPost);
//     free(rightIn);
//     free(rightPost);

//     return root;
// }

int insert(BinarySearchTree* tree, int data)
{
    if (tree->root == NULL)
    {
        tree->root = createNode(data);
    }
    
    Node* current = tree->root;

    while (data != current->data)
    {
        if (data < current->data)
        {
            if (current->left)
            {
                current = current->left;
            }
            else
            {
                current->left = createNode(data);
                return 1;
            }
        }
        if (data > current->data)
        {
            if (current->right)
            {
                current = current->right;
            }
            else
            {
                current->right = createNode(data);
                return 1;
            }
        }
    }
    return 0;
}

int delete(BinarySearchTree* tree, int value)
{
    Node* current = tree->root;
    Node* del, *delPrev;

    if (current->data == value)
    {
        del = tree->root;
    }
    else
    {
        while (current != NULL)
        {
            if (current->left && current->left->data == value)
            {
                delPrev = current;
                del = current->left;
                break;
            }
            else if (current->right && current->right->data == value)
            {
                delPrev = current;
                del = current->right;
                break;
            }
            
            if (value < current->data)
            {
                current = current->left;
            }
            else if (value > current->data)
            {
                current = current->right;
            }
        }
        if (current == NULL)
        {
            return 0;
        }
        
    }

    if (del->left && del->right)
    {
        current = del->left;
        while (del->right->data != current->data)
        {
            if (del->right->data < current->data)
            {
                if (current->left)
                {
                    current = current->left;
                }
                else
                {
                    current->left = del->right;
                    break;
                }
            }
            if (del->right->data > current->data)
            {
                if (current->right)
                {
                    current = current->right;
                }
                else
                {
                    current->right = del->right;
                    break;
                }
            }
        }
        if (del == tree->root)
        {
            tree->root = del->left;
        }
        else if (del->data < delPrev->data)
        {
            delPrev->left = del->left;
        }
        else if (del->data > delPrev->data)
        {
            delPrev->right = del->left;
        }
    }
    else if (del->left)
    {
        if (del == tree->root)
        {
            tree->root = del->left;
        }
        else if (del->data < delPrev->data)
        {
            delPrev->left = del->left;
        }
        else if (del->data > delPrev->data)
        {
            delPrev->right = del->left;
        }
    }
    else if (del->right)
    {
        if (del == tree->root)
        {
            tree->root = del->right;
        }
        else if (del->data < delPrev->data)
        {
            delPrev->left = del->right;
        }
        else if (del->data > delPrev->data)
        {
            delPrev->right = del->right;
        }
    }
    else
    {
        if (del == tree->root)
        {
            tree->root = NULL;
        }
        else if (del->data < delPrev->data)
        {
            delPrev->left = NULL;
        }
        else if (del->data > delPrev->data)
        {
            delPrev->right = NULL;
        }
    }

    free(del);
    return 1;
}

Node* searchTree(BinarySearchTree* tree, int key)
{
    Node* current = tree->root;

    while (current)
    {
        if (current->data == key)
        {
            return current;
        }
        if (key < current->data)
        {
            current = current->left;
        }
        if (key > current->data)
        {
            current = current->right;
        }
    }
    return NULL;
}

void printTreeInOrder(BinarySearchTree* tree)
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

void printTreePreOrder(BinarySearchTree* tree)
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

void printTreePostOrder(BinarySearchTree* tree)
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

void printTreePreOrderIterative(BinarySearchTree* tree)
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

void printTreeInOrderIterative(BinarySearchTree* tree)
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

void printTreeBreadthFirst(BinarySearchTree* tree)
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

void printTree2D(BinarySearchTree* tree)
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
