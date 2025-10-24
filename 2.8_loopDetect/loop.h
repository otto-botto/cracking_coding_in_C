#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>

int hello(void);

#define ARR_SIZE 26
/* Dynamic linked list, implemented as a stack */

typedef struct Node {
    char value;
    struct Node* next;
}Node;

typedef struct Stack {
    Node* head;
}Stack;

Node* makeNode(char letter);
Stack* makeStack(void);
void push(Stack* s, char letter);
int pop(Stack* s);
void destroyStack(Stack* s);

Node* detectLoop(Stack* s);