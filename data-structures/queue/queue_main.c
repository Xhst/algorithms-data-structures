#include <stdio.h>

#include "queue.c"

int main() {
    Queue* queue = new_queue();

    enqueue(queue, (int *)3);
    enqueue(queue, (int *)5);
    enqueue(queue, (int *)7);

    printf("Queue size: %d\n", size(queue));

    void* p = dequeue(queue);
    int v = *(int *)(&p);

    printf("Removed element %d, stack size after pop: %d\n", v, size(queue));
}