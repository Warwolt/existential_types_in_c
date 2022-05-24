#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#include "uint8_stack.h"

int main(void) {
    stack_init();
    printf("hello stack\n");

    stack_id_t stack = uint8_stack_create();

    uint8_t in[] = {12, 23, 34};
    uint8_stack_push(stack, in[0]);
    uint8_stack_push(stack, in[1]);
    uint8_stack_push(stack, in[2]);

    printf("%d\n", (*uint8_stack_pop(stack)));
    printf("%d\n", (*uint8_stack_pop(stack)));
    printf("%d\n", (*uint8_stack_pop(stack)));

    stack_destroy(stack);

    return 0;
}
