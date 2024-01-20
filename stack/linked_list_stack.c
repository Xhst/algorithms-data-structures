#include <stdio.h>
#include <stdlib.h>

#include "linked_list_stack.h"

ListStack* new_stack() {
    ListStack* stack = malloc(sizeof(ListStack));

    stack->head = NULL;
    stack->size = 0;

    return stack;
}

void push(ListStack* stack, void* object) {
    struct stack_elem* elem = malloc(sizeof(struct stack_elem));

    elem->value = object;
    elem->next = stack->head;

    stack->head = elem;
    stack->size++;
}

void* pop(ListStack* stack) {
    if (stack == NULL || stack->size == 0) return NULL;

    struct stack_elem* elem = stack->head;

    stack->head = elem->next;
    stack->size--;

    void* value = elem->value;
    
    free(elem);

    return value;
}

void* top(ListStack* stack) {
    if (stack == NULL || stack->head == NULL) return NULL;

    return stack->head->value;
}

int size(ListStack* stack) {
    if (stack == NULL) return 0;

    return stack->size;
}

int is_empty(ListStack* stack) {
    return stack == NULL || stack->size == 0;
}

void empty(ListStack* stack) {
    if (stack == NULL) return;

    struct stack_elem* temp;

    while (stack->head != NULL) {
        temp = stack->head;
        stack->head = temp->next;
        free(temp);
    }

    stack->head = NULL;
    stack->size = 0;
}