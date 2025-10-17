#include "2.1_removeDup.h"

int hello(void) {
    return 2;
}


Node* makeNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    assert(node);
    node->next = NULL;
    node->value = value;
    return node;
}

Stack* makeStack(void) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    assert(s);

    s->head = NULL;
    return s;
}


void push(Stack* s, int value) {
    assert(s);
    Node* node = makeNode(value);
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
        return INT_MIN;
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
    while (pop(s) != INT_MIN) {
        ;
    }
    free(s);
}
bool deleteNode(Stack* s, Node* n) {
    assert(s);
    assert(n);
    Node* tmp = s->head;

    if (n == tmp) {
        pop(s);
        return true;
    }else {

        while (tmp->next) {
            if (tmp->next == n) {
                Node* remove = tmp->next;
                tmp->next = remove->next;
                free(remove);
                return true;

            }else {
                tmp = tmp->next;
            }
        }
        return false;
    }
}