#include "loop.h"

int hello() {
    return 2;
}

Node* makeNode(char letter) {
    Node* node = (Node*)malloc(sizeof(Node));
    assert(node);
    node->next = NULL;
    node->value = letter;
    return node;
}

Stack* makeStack(void) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    assert(s);

    s->head = NULL;
    return s;
}

void push(Stack* s, char letter) {
    assert(s);
    Node* node = makeNode(letter);
    assert(node);

    if (s->head == NULL) {
        s->head = node;
    }else {
        Node* tmp = s->head;
        s->head = node;
        node->next = tmp;
    }
}

int pop(Stack* s) {
    if (s->head == NULL) {
        return 255;
    }else {
        Node* tmp = s->head;
        s->head = tmp->next;
        int value = tmp->value;
        free(tmp);
        return value;
    }
}

void destroyStack(Stack* s) {
    assert(s);
    while (pop(s) != 255) {
        ;
    }
    free(s);
}

Node* detectLoop(Stack* s) {
    Node* start = s->head;
    char arr[ARR_SIZE] = {0};

    while (start) {
        int index = start->value - 'A';
        if (arr[index] == 0) {
            arr[index] = start->value;
        }else {
            return start;
        }
        start = start->next;
    }

    fprintf(stderr, "No loop.\n");
}