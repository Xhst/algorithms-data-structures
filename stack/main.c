#include <stdio.h>

#include "stack.c"

void print_int_stack(Stack* stack) {
    for (int i = 0; i < stack->size; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

int main() {
    Stack* stack = new_stack();

    push(stack, 3);
    push(stack, 5);
    push(stack, 7);

    print_int_stack(stack);
    printf("Stack size: %d\n", size(stack));

    int v = pop(stack);

    printf("Removed element %d, stack size after pop: %d\n", v, size(stack));

    print_int_stack(stack);

}