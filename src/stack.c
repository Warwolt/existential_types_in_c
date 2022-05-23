#include "stack.h"

#include <stdlib.h>
#include <string.h>

#define STACK_INITIAL_CAPACITY 10

stack_t stack_create(size_t item_size) {
    return (stack_t) {
        .item_size = item_size,
        .item_buf = malloc(item_size * STACK_INITIAL_CAPACITY),
        .num_items = 0,
        .capacity = STACK_INITIAL_CAPACITY,
    };
}

void stack_destroy(const stack_t* stack) {
    free(stack->item_buf);
}

void stack_push(stack_t* stack, void* item) {
    // increase capacity if needed
    if (stack->num_items == stack->capacity) {
        stack->capacity *= 2;
        stack->item_buf = realloc(stack->item_buf, stack->capacity);
    }

    // push item
    const size_t offset = stack->item_size * stack->num_items;
    memcpy(stack->item_buf + offset, item, stack->item_size);
    stack->num_items += 1;
}

void* stack_pop(stack_t* stack) {
    // return void if empty
    if (stack->num_items == 0) {
        return NULL;
    }

    // pop item
    stack->num_items -= 1;
    void* item = stack->item_buf + stack->item_size * stack->num_items;
    return item;
}

bool stack_is_empty(const stack_t* stack) {
    return (stack->num_items == 0);
}
