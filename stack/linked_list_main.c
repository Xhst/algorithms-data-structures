#include <stdio.h>

#include "linked_list_stack.c"

void print_int_stack(ListStack* stack) {
    void* p;
    struct stack_elem* elem = stack->head;

    while (elem != NULL) {
        p = elem->value;
        printf("%d ", *((int *)(&p)));
        elem = elem->next;
    }
    printf("\n");
}

int main() {
    ListStack* stack = new_stack();

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