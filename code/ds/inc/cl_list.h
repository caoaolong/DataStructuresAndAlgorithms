//
// Created by admin on 25-6-9.
//

#ifndef CL_LIST_H
#define CL_LIST_H

#include <stdint.h>

// Circular Linked List

typedef struct cl_node_t {
    void *data;
    struct cl_node_t *prev;
    struct cl_node_t *next;
} cl_node;

typedef struct cl_list_t {
    cl_node *head;
    cl_node *tail;
    size_t size;
} cl_list;

// 创建双向链表
cl_list *cl_list_create();

// 创建双向链表节点
cl_node *cl_node_create(void *data);

// 从头部插入节点
void cl_list_insert_front(cl_list *list, cl_node *node);

// 从尾部插入节点
void cl_list_insert_back(cl_list *list, cl_node *node);

// 从指定节点处插入节点
void cl_list_insert(cl_list *list, int index, cl_node *node);

// 获取指定索引处的节点
cl_node *cl_list_node(const cl_list *list, int index);

// 从头部删除节点
cl_node *cl_list_remove_front(cl_list *list);

// 从尾部删除节点
cl_node *cl_list_remove_back(cl_list *list);

// 从指定节点处删除
cl_node *cl_list_remove(cl_list *list, int index);

// 回收双向链表
void cl_list_destroy(cl_list *list);

#endif //CL_LIST_H
