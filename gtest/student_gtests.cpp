// ------------------------- Your tests - student_gtests.cpp ----------------------------- //
// Your own GoogleTest suite for the Stack module. It is graded: the autograder runs it against
// a correct Stack and against several Stacks with one bug each. A test is worth something only
// when it passes on the correct Stack and fails on a broken one, so a test that always fails
// (or that tests nothing) earns nothing.
//
// Two examples are given. Add tests of your own for pop, push_all, pop_all, and the edges
// (an empty stack, a stack of one character, a full stack).
// --------------------------------------------------------------------------------------- //

#include <gtest/gtest.h>

#include "stack.hpp"

TEST(StackTests, NewStackIsEmptyAndNotFull) {
    Stack stk;
    EXPECT_TRUE(stk.isEmpty());
    EXPECT_FALSE(stk.isFull());
}

TEST(StackTests, PushThenTopSeesTheCharacter) {
    Stack stk;
    stk.push('z');
    EXPECT_EQ(stk.top(), 'z');
}

// ADD YOUR TESTS HERE

// catches: pop() on an empty stack not returning '@'
TEST(StackTests, PopOnEmptyReturnsAt) {
    Stack stk;
    EXPECT_EQ(stk.pop(), '@');
}

// catches: wrong order, or pop() not actually removing
TEST(StackTests, PopReturnsLastPushedFirst) {
    Stack stk;
    stk.push('a');
    stk.push('b');
    EXPECT_EQ(stk.pop(), 'b');
    EXPECT_EQ(stk.pop(), 'a');
    EXPECT_TRUE(stk.isEmpty());
}

// catches: wrong capacity, or a push on a full stack overwriting data
TEST(StackTests, FullStackIgnoresExtraPush) {
    Stack stk;
    for (int i = 0; i < STK_MAX - 1; ++i) {
        stk.push('a');
    }
    EXPECT_FALSE(stk.isFull());
    stk.push('b');
    EXPECT_TRUE(stk.isFull());
    stk.push('c');
    EXPECT_EQ(stk.top(), 'b');
}

