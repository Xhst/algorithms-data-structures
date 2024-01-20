#include <stdio.h>
#include <stdlib.h>

#include "queue.h"


Queue* new_queue() {
    Queue* queue = malloc(sizeof(Queue));

    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    return queue;
}

void enqueue(Queue* queue, void* object) {
    if (queue == NULL) return;

    queue->size++;

    if (queue->head == NULL) {
        queue->head = (struct queue_node *) malloc(sizeof(struct queue_node));
        queue->head->value = object;
        queue->head->prev = NULL;
        queue->tail = queue->head;
        return;
    }

    struct queue_node* temp = malloc(sizeof(struct queue_node));
    temp->value = object;
    temp->next = queue->tail;
    queue->tail = temp;
}

void* dequeue(Queue* queue) {
    if (queue == NULL || queue->head == NULL) return NULL;

    void* value = peek(queue);

    struct queue_node* temp = queue->head;

    queue->head = temp->prev;
    queue->size--;

    free(temp);

    return value;
}

void* peek(Queue* queue) {
    if (queue == NULL || queue->head == NULL) return NULL;

    return queue->head->value;
}

int size(Queue* queue) {
    if (queue == NULL) return 0;

    return queue->size;
}

int is_empty(Queue* queue) {
    return queue == NULL || queue->size == 0;
}