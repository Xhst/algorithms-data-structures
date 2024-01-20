#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

Stack* new_stack() {
    Stack* stack = malloc(sizeof(Stack));

    stack->array = malloc(sizeof(int) * INITIAL_STACK_SIZE);
    stack->current_max_size = 5;
    stack->size = 0;
    stack->top_element_offset = -1;

    return stack;
}

/**
 * Function used to implement telescopic stack management.
 * Strategy to have no limit on the size of the stack:
 *  - A default initial size is used.
 *  - When a push is performed on the full stack the stack size
 *    is increased to be able to insert new elements.
 */
void telescopic_grow(Stack* stack) {
    if (stack == NULL) return;

    stack->current_max_size += INITIAL_STACK_SIZE;

    int* temp = malloc(sizeof(int) * stack->current_max_size);

    for (int i = 0; i < stack->current_max_size - INITIAL_STACK_SIZE; i++) {
        *(temp + i) = *(stack->array + i);
    }

    free(stack->array);

    stack->array = temp;
}

void push(Stack* stack, int value) {
    if (stack == NULL) return;

    if (stack->size == stack->current_max_size) {
        telescopic_grow(stack);
        push(stack, value);
        return;
    }

    stack->top_element_offset++;
    stack->size++;

    *(stack->array + stack->top_element_offset) = value;
}

int pop(Stack* stack) {
    int t = top(stack);

    stack->top_element_offset--;
    stack->size--;

    return t;
}

int top(Stack* stack) {
    return stack->array[stack->top_element_offset];
}

int size(Stack* stack) {
    if (stack == NULL) return 0;

    return stack->size;
}

int is_empty(Stack* stack) {
    if (stack == NULL) return 1;

    return stack->size == 0;
}

void empty(Stack* stack) {
    if (stack == NULL) return;

    stack->size = 0;
    stack->top_element_offset = -1;
}