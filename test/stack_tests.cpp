#include <gtest/gtest.h>

extern "C" {
    #include "stack.h"
}

class stack_tests : public ::testing::Test {
public:
    void SetUp() override {
        stack_init();
    }
};

TEST_F(stack_tests, initial_stack_empty) {
    stack_id_t stack = stack_create(sizeof(int));

    ASSERT_TRUE(stack_is_empty(stack));
    stack_destroy(stack);
}

TEST_F(stack_tests, pushing_onto_stack_makes_it_non_empty) {
    stack_id_t stack = stack_create(sizeof(int));
    int val = 3;

    stack_push(stack, &val);

    ASSERT_FALSE(stack_is_empty(stack));
    stack_destroy(stack);
}

TEST_F(stack_tests, popping_empty_stack_gives_back_nothing) {
    stack_id_t stack = stack_create(sizeof(int));

    void* item = stack_pop(stack);

    ASSERT_EQ(item, nullptr);
    stack_destroy(stack);
}

TEST_F(stack_tests, popping_pushed_item_gives_back_that_item) {
    stack_id_t stack = stack_create(sizeof(int));
    int input = 42;

    stack_push(stack, &input);
    int* item = (int*)stack_pop(stack);

    ASSERT_EQ(*item, input);
    stack_destroy(stack);
}

TEST_F(stack_tests, pushed_items_are_popped_in_reverse_order) {
    stack_id_t stack = stack_create(sizeof(int));
    int input[] = {1, 2, 3};

    stack_push(stack, &input[0]);
    stack_push(stack, &input[1]);
    stack_push(stack, &input[2]);

    ASSERT_EQ(*(int*)stack_pop(stack), input[2]);
    ASSERT_EQ(*(int*)stack_pop(stack), input[1]);
    ASSERT_EQ(*(int*)stack_pop(stack), input[0]);

    stack_destroy(stack);
}
