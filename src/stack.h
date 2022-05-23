#include <stdint.h>
#include <stdbool.h>

typedef struct stack_id {
    size_t val;
} stack_id_t;

void stack_init(); // initialize stack system
stack_id_t stack_create(size_t item_size);
void stack_destroy(stack_id_t stack_id);
void stack_push(stack_id_t stack_id, void* item);
void* stack_pop(stack_id_t stack_id);
bool stack_is_empty(stack_id_t stack_id);
