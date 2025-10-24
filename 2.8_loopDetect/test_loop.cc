#include "gtest/gtest.h"

extern "C"{
#include "loop.h"
}

TEST(LoopTest, TestHello){
    EXPECT_EQ(2, hello());
}


TEST(LoopTest, TestMakeStack) {
    Stack* s = makeStack();
    Node* a = makeNode('A');
    Node* b = makeNode('B');
    Node* c = makeNode('C');
    Node* d = makeNode('D');

    s->head = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = c;

    EXPECT_EQ(a->next->next->value, 'C');
}

TEST(LoopTest, TestDetectLoop) {
    Stack* s = makeStack();
    Node* a = makeNode('A');
    Node* b = makeNode('B');
    Node* c = makeNode('C');
    Node* d = makeNode('D');

    s->head = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = c;

    EXPECT_EQ(c, detectLoop(s));
}