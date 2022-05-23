#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

// [x] create
// [x] destroy
// [x] push
// [ ] pop
// [ ] is_empty

#define STACK_INITIAL_CAPACITY 10

typedef struct stack {
    const size_t item_size;
    uint8_t* item_buf;
    size_t num_items;
    size_t capacity;
} stack_t;

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
    void* item = stack->item_buf + stack->item_size * stack->num_items;
    stack->num_items -= 1;
    return item;
}

int main(void) {
    stack_t stack = stack_create(sizeof(int));

    int in[] = {123, 234, 345};
    stack_push(&stack, &in[0]);
    stack_push(&stack, &in[1]);
    stack_push(&stack, &in[2]);

    int out[3];
    out[0] = *(uint32_t*)stack_pop(&stack);
    out[1] = *(uint32_t*)stack_pop(&stack);
    out[2] = *(uint32_t*)stack_pop(&stack);

    printf("out[0] = %d\n", out[0]);
    printf("out[1] = %d\n", out[1]);
    printf("out[2] = %d\n", out[2]);

    // assert(*(uint32_t*)stack_pop(&stack) == 3);
    // assert(*(uint32_t*)stack_pop(&stack) == 2);
    // assert(*(uint32_t*)stack_pop(&stack) == 1);
    // assert(stack_pop(&stack) == NULL);

    stack_destroy(&stack);

    printf("hello\n");

    return 0;
}
