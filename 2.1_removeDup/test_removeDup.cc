#include "gtest/gtest.h"

extern "C"{
#include "2.1_removeDup.h"
}

TEST(RemoveDup, TestHello) {
    EXPECT_EQ(2, hello());
}

TEST(RemoveDup, TestMakeStack) {
    Stack* s = makeStack();
    assert(s);

    for (int i = 0; i < 9; i++) {
        push(s, i);
    }

    EXPECT_EQ(s->head->value, 8);
    EXPECT_EQ(s->head->next->next->next->value, 5);

    pop(s);
    EXPECT_EQ(s->head->value, 7);
    push(s, 7);
    EXPECT_EQ(s->head->value, 7);
    EXPECT_EQ(s->head->next->value, 7);
    Node* node = s->head->next->next;
    deleteNode(s, node);

    EXPECT_EQ(s->head->next->next->value, 5);

    destroyStack(s);

}