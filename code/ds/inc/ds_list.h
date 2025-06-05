//
// Created by admin on 25-6-5.
//

#ifndef DS_LIST_H
#define ds_LIST_H

#include <stdint.h>

// Singly linked list

typedef struct sl_node_t {
    struct sl_node_t *next;
    void *data;
} sl_node;

typedef struct sl_list_t {
    sl_node *head;
    sl_node *tail;
    size_t size;
} sl_list;

// 创建单向链表
sl_list *sl_list_create();

// 创建单向链表节点
sl_node *sl_node_create(void *data);

// 从头部插入节点
void sl_list_insert_front(sl_list *list, sl_node *node);

// 从尾部插入节点
void sl_list_insert_back(sl_list *list, sl_node *node);

// 从指定节点处插入节点
void sl_list_insert(sl_list *list, sl_node *inode, sl_node *node);

// 获取指定索引处的节点
sl_node *sl_list_node(const sl_list *list, int index);

// 从头部删除节点
sl_node *sl_list_remove_front(sl_list *list);

// 从尾部删除节点
sl_node *sl_list_remove_back(sl_list *list);

// 从指定节点处删除
sl_node *sl_list_remove(sl_list *list, int index);

// 回收单向链表
void sl_list_destroy(sl_list *list);

#endif //ds_LIST_H
