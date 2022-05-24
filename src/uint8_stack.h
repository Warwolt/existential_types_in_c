#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "stack.h"

stack_id_t uint8_stack_create();
void uint8_stack_destroy(stack_id_t stack_id);
void uint8_stack_push(stack_id_t stack_id, uint8_t item);
uint8_t* uint8_stack_pop(stack_id_t stack_id);
bool uint8_stack_is_empty(stack_id_t stack_id);
