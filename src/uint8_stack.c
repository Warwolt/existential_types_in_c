#include "uint8_stack.h"

stack_id_t uint8_stack_create() {
    return stack_create(sizeof(uint8_t));
}

void uint8_stack_destroy(stack_id_t stack_id) {
    stack_destroy(stack_id);
}

void uint8_stack_push(stack_id_t stack_id, uint8_t item) {
    stack_push(stack_id, &item);
}

uint8_t* uint8_stack_pop(stack_id_t stack_id) {
    return stack_pop(stack_id);
}

bool uint8_stack_is_empty(stack_id_t stack_id) {
    return stack_is_empty(stack_id);
}
