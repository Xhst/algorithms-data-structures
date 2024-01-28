#include <stdio.h>
#include <stdlib.h>

#include "list.h"

List* new_list() {
    List* list = malloc(sizeof(List));

    list->first = NULL;
    list->size = 0;

    return list;
}

void* get(List* list, int position) {
    list_node* node = list->first;
    int pos = 0;

    if (position > list->size - 1) return NULL;

    while (pos < position) {
        node = node->next;
        pos++;
    }

    return node->value;
}

void add(List* list, void* object) {
    list_node* node = malloc(sizeof(list_node));
    node->value = object;

    if (list->first != NULL) {
        node->next = list->first;
    }

    list->first = node;
    list->size++;
}

void remove_at(List* list, int position) {
    list_node* prev;
    list_node* node = list->first;
    int pos = 0;

    if (position > list->size - 1) return;

    while (pos < position) {
        prev = node;
        node = node->next;
        pos++;
    }

    prev->next = node->next;
    list->size--;

    free(node);
}

int size(List* list) {
    if (list == NULL) return 0;

    return list->size;
}

int is_empty(List* list) {
    return list == NULL || list->size == 0;
}
