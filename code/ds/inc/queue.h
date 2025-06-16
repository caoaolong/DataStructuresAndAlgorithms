//
// Created by admin on 25-6-16.
//

#ifndef QUEUE_H
#define QUEUE_H

#include <array.h>
#include <dl_list.h>

typedef array queue_array;

// 队列（数组实现，前入后出）

queue_array *queue_array_create();

void queue_array_enqueue(queue_array *queue, void *data);

void *queue_array_dequeue(queue_array *queue);

void *queue_array_peek(const queue_array *queue);

// 队列（双向链表实现）

typedef dl_list queue_list;
typedef dl_node queue_node;

queue_list *queue_list_create();

queue_node *queue_node_create(void *data);

void queue_list_enqueue(queue_list *queue, queue_node *node);

queue_node *queue_list_dequeue(queue_list *queue);

queue_node *queue_list_peek(const queue_list *queue);

#endif //QUEUE_H
