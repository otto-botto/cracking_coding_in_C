#include "gtest/gtest.h"

extern "C"{
#include "three.h"
}

TEST(ThreeStacks, TestInitStack) {
    FixedStack myStack;
    initFixedStack(&myStack);
    EXPECT_EQ(myStack.capacity, 100);
    EXPECT_EQ(myStack.values[10], INT_MIN);
}

TEST(ThreeStacks, TestPush) {
    FixedStack myStack;
    initFixedStack(&myStack);
    EXPECT_TRUE(isEmpty(&myStack, 0));
    EXPECT_TRUE(isEmpty(&myStack, 1));
    EXPECT_TRUE(isEmpty(&myStack, 2));

    push(&myStack, 0, 10);
    push(&myStack, 1, 20);
    push(&myStack, 2, 30);
    push(&myStack, 0, 11);

    EXPECT_EQ(myStack.values[myStack.stackCapacities[0]], 11);
    EXPECT_EQ(myStack.values[0], 10);
    EXPECT_EQ(myStack.values[myStack.stackCapacities[1]], 20);
    EXPECT_EQ(myStack.values[myStack.stackCapacities[2]], 30);
}

TEST(ThreeStacks, TestPop) {
    FixedStack myStack;
    initFixedStack(&myStack);
    //pop(&myStack, 0);

    push(&myStack, 0, 10);
    push(&myStack, 1, 20);
    push(&myStack, 2, 30);
    push(&myStack, 0, 11);

    pop(&myStack, 0);
    EXPECT_EQ(myStack.values[myStack.stackCapacities[0]], 10);
    pop(&myStack, 0);
    EXPECT_EQ(myStack.stackCapacities[0], -1);
    EXPECT_EQ(myStack.stackCapacities[1], 33);
    EXPECT_EQ(myStack.stackCapacities[2], 66);
    pop(&myStack, 1);
    pop(&myStack, 2);
    EXPECT_EQ(myStack.stackCapacities[0], -1);
    EXPECT_EQ(myStack.stackCapacities[1], 32);
    EXPECT_EQ(myStack.stackCapacities[2], 65);
    EXPECT_TRUE(isEmpty(&myStack, 0));
    EXPECT_TRUE(isEmpty(&myStack, 1));
    EXPECT_TRUE(isEmpty(&myStack, 2));

}