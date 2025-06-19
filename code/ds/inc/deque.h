//
// Created by admin on 25-6-19.
//

#ifndef DEQUE_H
#define DEQUE_H

#include <dl_list.h>

typedef dl_list deque;
typedef dl_node deque_node;

#define deque_create                dl_list_create
#define deque_push_back(V, N)       dl_list_insert_back(V, dl_node_create(N))
#define deque_pop_back              dl_list_remove_back
#define deque_push_front(V, N)      dl_list_insert_front(V, dl_node_create(N))
#define deque_pop_front             dl_list_remove_front
#define deque_front(V)              (V)->head
#define deque_back(V)               (V)->tail
#define deque_destroy(V)            dl_list_destroy

#endif //DEQUE_H
