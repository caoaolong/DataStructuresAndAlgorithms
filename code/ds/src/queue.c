//
// Created by admin on 25-6-16.
//
#include <queue.h>

void queue_array_enqueue(queue_array *queue, void *data) {
    return array_insert_front(queue, data);
}

void *queue_array_dequeue(queue_array *queue) {
    return array_remove_back(queue);
}

void *queue_array_peek(const queue_array *queue) {
    return array_node(queue, (int)queue->size - 1);
}

queue_list *queue_list_create() {
    return dl_list_create();
}

queue_node *queue_node_create(void *data) {
    return dl_node_create(data);
}

void queue_list_enqueue(queue_list *queue, queue_node *node) {
    return dl_list_insert_front(queue, node);
}

queue_node *queue_list_dequeue(queue_list *queue) {
    return dl_list_remove_back(queue);
}

queue_node *queue_list_peek(const queue_list *queue) {
    return queue->tail;
}