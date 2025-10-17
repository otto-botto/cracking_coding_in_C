#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
/* Dynamic linked list, implemented as a stack */

typedef struct Node {
    int value;
    struct Node* next;
}Node;

typedef struct Stack {
    Node* head;
}Stack;

Node* makeNode(int value);
Stack* makeStack(void);
void push(Stack* s, int value);
int pop(Stack* s);
void destroyStack(Stack* s);
bool deleteNode(Stack* s, Node* n);
bool insertAfter(Stack* s, Node* n, int data);


int hello(void);
