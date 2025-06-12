//
// Created by admin on 25-6-9.
//
#include <cl_list.h>
#include <stdlib.h>

// 创建双向链表
cl_list *cl_list_create() {
    cl_list *list = malloc(sizeof(cl_list));
    list->head = list->tail = NULL;
    list->size = 0;
    return list;
}

// 创建双向链表节点
cl_node *cl_node_create(void *data) {
    cl_node *node = malloc(sizeof(cl_node));
    node->data = data;
    node->prev =node->next = NULL;
    return node;
}

static void cl_list_insert_only_one(cl_list *list, cl_node *node) {
    list->head = list->tail = node;
    node->prev = node->next = node;
    list->size++;
}

// 从头部插入节点
void cl_list_insert_front(cl_list *list, cl_node *node) {
    // 链表为NULL的情况
    if (!list || !node) return;
    // 链表为空的情况
    if (list->head == NULL) {
        cl_list_insert_only_one(list, node);
        return;
    }

    // 核心逻辑
    node->next = list->head;
    list->head->prev = node;
    node->prev = list->tail;
    list->head = node;
    list->size++;
}

// 从尾部插入节点
void cl_list_insert_back(cl_list *list, cl_node *node) {
    // 链表为NULL的情况
    if (!list || !node) return;
    // 链表为空的情况
    if (list->head == NULL) {
        cl_list_insert_only_one(list, node);
        return;
    }

    // 核心逻辑
    node->prev = list->tail;
    list->tail->next = node;
    node->next = list->head;
    list->tail = node;
    list->size++;
}

// 从指定节点处插入节点
void cl_list_insert(cl_list *list, const int index, cl_node *node) {
    // 链表为NULL的情况
    if (!list || !node) return;
    // 等同于从头部插入
    if (index == 0) {
        cl_list_insert_front(list, node);
        return;
    }
    // 等同于从尾部插入
    if (index == list->size - 1) {
        cl_list_insert_back(list, node);
    }

    // 核心逻辑(可优化)
    /** 优化方案：
     *  根据index距离0和size-1的大小判断是从head开始索引还是从tail开始索引
     */
    cl_node *p = list->head;
    for (int i = 0; i < index - 1; i++) {
        p = p->next;
    }
    node->next = p->next;
    p->next->prev = node;
    node->prev = p;
    p->next = node;
    list->size++;
}

// 获取指定索引处的节点
cl_node *cl_list_node(const cl_list *list, const int index) {
    // 索引越界的情况
    if (!list || index < 0 || index >= list->size) {
        return NULL;
    }

    // 核心逻辑(可优化)
    /** 优化方案：
     *  根据index距离0和size-1的大小判断是从head开始索引还是从tail开始索引
     */
    cl_node *node = list->head;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    return node;
}

static cl_node *cl_list_remove_only_one(cl_list *list) {
    cl_node *node = list->head;
    list->head = list->tail = NULL;
    list->size--;
    return node;
}

// 从头部删除节点
cl_node *cl_list_remove_front(cl_list *list) {
    // 链表为空或者NULL的情况
    if (!list || list->head == NULL) {
        return NULL;
    }
    // 链表只有一个节点的情况
    if (list->head == list->tail) {
        return cl_list_remove_only_one(list);
    }

    // 核心逻辑
    cl_node *node = list->head;
    list->head = list->head->next;
    list->head->prev = list->tail;
    list->size--;
    return node;
}

// 从尾部删除节点
cl_node *cl_list_remove_back(cl_list *list) {
    // 链表为空或者NULL的情况
    if (!list || list->head == NULL) {
        return NULL;
    }
    // 链表只有一个节点的情况
    if (list->head == list->tail) {
        return cl_list_remove_only_one(list);
    }

    // 核心逻辑
    cl_node *node = list->tail;
    list->tail = list->tail->prev;
    list->tail->next = list->head;
    list->size--;
    return node;
}

// 从指定节点处删除
cl_node *cl_list_remove(cl_list *list, const int index) {
    // 链表为空或者NULL的情况
    if (!list || index < 0 || index >= list->size) {
        return NULL;
    }
    // 等同于从头部删除
    if (index == 0) {
        return cl_list_remove_front(list);
    }
    // 等同于从尾部删除
    if (index == list->size - 1) {
        return cl_list_remove_back(list);
    }

    // 核心逻辑(可优化)
    /** 优化方案：
     *  根据index距离0和size-1的大小判断是从head开始索引还是从tail开始索引
     */
    cl_node *node = list->head;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    node->next->prev = node->prev;
    node->prev->next = node->next;
    list->size--;
    return node;
}

// 回收双向链表
void cl_list_destroy(cl_list *list) {
    if (!list) return;
    cl_node *p = list->head;
    while (p) {
        cl_node *next = p->next;
        free(p);
        p = next;
    }
    free(list);
}