#ifndef __LIST_H__
#define __LIST_H__

typedef struct list_node {
    void* value;
    struct node* next;
} list_node;

typedef struct list {
    struct list_node* first;
    int size;
} List;

/**
 * Returns reference to an empty list.
 */
struct list* new_list();

/**
 * Returns the element at position.
 */
void* get(struct list* list, int position);

/**
 * Add an element to the list.
 */
void add(struct list* list, void* object);

/**
 * Remove the element at position.
 */
void remove_at(struct list* list, int position);

/**
 * Remove first element with the given value.
 */
void remove_first(struct list* list, void* value);

/**
 * Remove all elements with the given value.
 */
void remove_all(struct list* list, void* value);

/**
 * Returns the size of the list.
 */
int size(struct list* list);

/**
 * Returns 1 if the list is empty, 0 otherwise.
 */
int is_empty(struct list* list);

#endif