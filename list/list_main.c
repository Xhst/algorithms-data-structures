#include <stdio.h>

#include "list.c"

void print_int_list(List* list) {
    void* p;
    list_node* node = list->first;

    while (node != NULL) {
        p = node->value;
        printf("%d ", *((int *)(&p)));
        node = node->next;
    }
    printf("\n");
}

int main() {
    List* list = new_list();

    add(list, (int *)1);
    add(list, (int *)2);
    add(list, (int *)3);
    add(list, (int *)4);
    add(list, (int *)7);
    add(list, (int *)5);
    add(list, (int *)6);
    add(list, (int *)7);

    print_int_list(list);
    printf("List size: %d\n", size(list));

    remove_at(list, 3);

    print_int_list(list);
    printf("List size: %d\n", size(list));

    void* p = get(list, 4);
    int v = *(int *)(&p);

    printf("Element at position 4 is: %d\n", v);


}