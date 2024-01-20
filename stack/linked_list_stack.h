#ifndef __LL_STACK_H__
#define __LL_STACK_H__

struct stack_elem {
    void* value;
    struct stack_elem* next;
};

typedef struct ll_stack {
   struct stack_elem* head;
   int size;
} ListStack;

/**
 * Returns reference to an empty stack.
 */
struct ll_stack* new_stack();

/**
 * Inserts an element into the stack.
 */
void push(struct ll_stack* stack, void* object);

/**
 * Removes and returns the outcropping element of the stack.
 */
void* pop(struct ll_stack* stack);

/**
 * Returns the outcropping element of the stack.
 */
void* top(struct ll_stack* stack);

/**
 * Returns the number of elements in the stack.
 */
int size(struct ll_stack* stack);

/**
 * Returns 1 if the stack is empty, 0 otherwise.
 */
int is_empty(struct ll_stack* stack);

/**
 * Empty the stack.
 */
void empty(struct ll_stack* stack);



#endif