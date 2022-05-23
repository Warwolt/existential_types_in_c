#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#include "stack.h"

int main(void) {
    stack_init();
    printf("hello stack\n");

    stack_id_t stack = stack_create(sizeof(uint8_t));

    uint8_t in[] = {12, 23, 34};
    stack_push(stack, &in[0]);
    stack_push(stack, &in[1]);
    stack_push(stack, &in[2]);

    printf("%d\n", (*(uint8_t*)stack_pop(stack)));
    printf("%d\n", (*(uint8_t*)stack_pop(stack)));
    printf("%d\n", (*(uint8_t*)stack_pop(stack)));

    stack_destroy(stack);

    return 0;
}
