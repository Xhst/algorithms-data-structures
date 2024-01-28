#include <stdio.h>

#include "array_stack.c"

void print_int_stack(Stack* stack) {
    void* p;
    for (int i = 0; i < stack->size; i++) {
        p = stack->array[i];
        printf("%d ", *((int *)(&p)));
    }
    printf("\n");
}

int main() {
    Stack* stack = new_stack();

    push(stack, (int *)3);
    push(stack, (int *)5);
    push(stack, (int *)7);

    print_int_stack(stack);
    printf("Stack size: %d\n", size(stack));

    void* p = pop(stack);
    int v = *(int *)(&p);

    printf("Removed element %d, stack size after pop: %d\n", v, size(stack));

    print_int_stack(stack);

}