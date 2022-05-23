#include "stack.h"

#include <stdlib.h>
#include <string.h>

typedef struct stack {
    const size_t item_size;
    uint8_t* item_buf;
    size_t num_items;
    size_t capacity;
} stack_t;

#define INITIAL_STACK_CAPACITY 10
#define MAX_NUM_STACKS 1024

static stack_t m_stacks[MAX_NUM_STACKS];
static size_t m_top_id;

void stack_init() {
    m_top_id = 0;
}

stack_id_t stack_create(size_t item_size) {
    stack_t stack = (stack_t) {
        .item_size = item_size,
        .item_buf = malloc(item_size * INITIAL_STACK_CAPACITY),
        .num_items = 0,
        .capacity = INITIAL_STACK_CAPACITY,
    };
    memcpy(&m_stacks[m_top_id], &stack, sizeof(stack_t));

    stack_id_t stack_id = (stack_id_t) { .val = m_top_id };
    m_top_id += 1;

    return stack_id;
}

void stack_destroy(stack_id_t stack_id) {
    const stack_t* stack = &m_stacks[stack_id.val];
    free(stack->item_buf);
}

void stack_push(stack_id_t stack_id, void* item) {
    stack_t* stack = &m_stacks[stack_id.val];

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

void* stack_pop(stack_id_t stack_id) {
    stack_t* stack = &m_stacks[stack_id.val];

    // return void if empty
    if (stack->num_items == 0) {
        return NULL;
    }

    // pop item
    stack->num_items -= 1;
    void* item = stack->item_buf + stack->item_size * stack->num_items;
    return item;
}

bool stack_is_empty(stack_id_t stack_id) {
    const stack_t* stack = &m_stacks[stack_id.val];
    return (stack->num_items == 0);
}
