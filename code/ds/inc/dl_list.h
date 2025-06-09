//
// Created by admin on 25-6-9.
//

#ifndef DL_LIST_H
#define DL_LIST_H

#include <stdint.h>

// Doubly linked list

typedef struct dl_node_t {
    void *data;
    struct dl_node_t *prev;
    struct dl_node_t *next;
} dl_node;

typedef struct dl_list_t {
    dl_node *head;
    dl_node *tail;
    size_t size;
} dl_list;

// 创建双向链表
dl_list *dl_list_create();

// 创建双向链表节点
dl_node *dl_node_create(void *data);

// 从头部插入节点
void dl_list_insert_front(dl_list *list, dl_node *node);

// 从尾部插入节点
void dl_list_insert_back(dl_list *list, dl_node *node);

// 从指定节点处插入节点
void dl_list_insert(dl_list *list, int index, dl_node *node);

// 获取指定索引处的节点
dl_node *dl_list_node(const dl_list *list, int index);

// 从头部删除节点
dl_node *dl_list_remove_front(dl_list *list);

// 从尾部删除节点
dl_node *dl_list_remove_back(dl_list *list);

// 从指定节点处删除
dl_node *dl_list_remove(dl_list *list, int index);

// 回收双向链表
void dl_list_destroy(dl_list *list);

#endif //DL_LIST_H
