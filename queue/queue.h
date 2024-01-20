#ifndef __QUEUE_H__
#define __QUEUE_H__

struct queue_node {
    void* value;
    struct queue_node* next;
    struct queue_node* prev;
};

typedef struct queue {
    struct queue_node* head;
    struct queue_node* tail;
    int size;
} Queue;

/**
 * Returns reference to an empty queue.
 */
struct queue* new_queue();

/**
 * Add an element to the queue.
 */
void enqueue(struct queue* queue, void* object);

/**
 * Returns and remove the oldest element in the queue.
 */
void* dequeue(struct queue* queue);

/**
 * Returns the oldest element in the queue.
 */
void* peek(struct queue* queue);

/**
 * Returns the number of elements in the queue.
 */
int size(struct queue* queue);

/**
 * Returns 1 if the queue is empty, 0 otherwise.
 */
int is_empty(struct queue* queue);

#endif