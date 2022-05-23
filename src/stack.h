#include <stdint.h>
#include <stdbool.h>

typedef struct stack {
    const size_t item_size;
    uint8_t* item_buf;
    size_t num_items;
    size_t capacity;
} stack_t;

stack_t stack_create(size_t item_size);
void stack_destroy(const stack_t* stack);
void stack_push(stack_t* stack, void* item);
void* stack_pop(stack_t* stack);
bool stack_is_empty(const stack_t* stack);
