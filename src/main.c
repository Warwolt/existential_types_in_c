#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

#include "stack.h"

int main(void) {
    stack_t stack = stack_create(sizeof(uint8_t));

    uint8_t in[] = {12, 23, 34};
    stack_push(&stack, &in[0]);
    stack_push(&stack, &in[1]);
    stack_push(&stack, &in[2]);

    assert(!stack_is_empty(&stack));
    assert(*(uint8_t*)stack_pop(&stack) == 34);
    assert(*(uint8_t*)stack_pop(&stack) == 23);
    assert(*(uint8_t*)stack_pop(&stack) == 12);
    assert(stack_pop(&stack) == NULL);
    assert(stack_is_empty(&stack));

    stack_destroy(&stack);

    return 0;
}
