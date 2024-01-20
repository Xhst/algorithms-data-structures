#ifndef __STACK_H__
#define __STACK_H__

#define INITIAL_STACK_SIZE 15

typedef struct stack {
   int* array;
   int current_max_size;
   int size;
   int top_element_offset;
} Stack;

/**
 * Returns reference to an empty stack.
 */
struct stack* new_stack();

/**
 * Inserts an element into the stack.
 */
void push(struct stack* stack, int value);

/**
 * Removes and returns the outcropping element of the stack.
 */
int pop(struct stack* stack);

/**
 * Returns the outcropping element of the stack.
 */
int top(struct stack* stack);

/**
 * Returns the number of elements in the stack.
 */
int size(struct stack* stack);

/**
 * Returns 1 if the stack is empty, 0 otherwise.
 */
int is_empty(struct stack* stack);

/**
 * Empty the stack.
 */
void empty(struct stack* stack);



#endif