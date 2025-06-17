//
// Created by admin on 25-6-16.
//

#ifndef QUEUE_H
#define QUEUE_H

#include <array.h>
#include <dl_list.h>

// 队列（数组实现，前入后出）

typedef array queue_array;

#define queue_array_create          array_create
#define queue_array_destroy         array_destroy
#define queue_array_enqueue         array_insert_back
#define queue_array_dequeue         array_remove_front
#define queue_list_peek(V)          array_node((V), (int)(V)->size - 1)

// 队列（双向链表实现）

typedef dl_list queue_list;
typedef dl_node queue_node;

#define queue_list_create           dl_list_create
#define queue_node_create           dl_node_create
#define queue_list_enqueue          dl_list_insert_back
#define queue_list_dequeue          dl_list_remove_front
#define queue_list_peek(V)          (V)->tail

#endif //QUEUE_H
