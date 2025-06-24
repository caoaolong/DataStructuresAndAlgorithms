//
// Created by admin on 25-6-5.
//
#include <sl_list.h>
#include <stdlib.h>

// 创建单向链表
sl_list *sl_list_create() {
    sl_list *list = malloc(sizeof(sl_list));
    list->head = list->tail = NULL;
    list->size = 0;
    return list;
}

// 创建单向链表节点
sl_node *sl_node_create(const int64_t data) {
    sl_node *node = malloc(sizeof(sl_node));
    node->data = data;
    node->next = NULL;
    return node;
}

// 从头部插入节点
void sl_list_insert_front(sl_list *list, sl_node *node) {
    // 链表为NULL的情况
    if (!list || !node) return;
    // 链表为空的情况
    if (list->head == NULL) {
        list->head = list->tail = node;
        list->size++;
        return;
    }

    // 核心逻辑
    node->next = list->head;
    list->head = node;
    list->size++;
}

// 从尾部插入节点
void sl_list_insert_back(sl_list *list, sl_node *node) {
    // 链表为NULL的情况
    if (!list || !node) return;
    // 链表为空的情况
    if (list->head == NULL) {
        list->head = list->tail = node;
        list->size++;
        return;
    }

    // 核心逻辑
    list->tail->next = node;
    list->tail = node;
    list->size++;
}

// 从指定节点处插入节点
void sl_list_insert(sl_list *list, const int index, sl_node *node) {
    // 链表为NULL的情况
    if (!list || !node) return;
    // 等同于从头部插入
    if (index == 0) {
        sl_list_insert_front(list, node);
        return;
    }
    // 等同于从尾部插入
    if (index == list->size - 1) {
        sl_list_insert_back(list, node);
    }

    // 核心逻辑
    sl_node *p = list->head;
    for (int i = 0; i < index - 1; i++) {
        p = p->next;
    }
    node->next = p->next;
    p->next = node;
    list->size++;
}

// 获取指定索引处的节点
sl_node *sl_list_node(const sl_list *list, const int index) {
    // 索引越界的情况
    if (!list || index < 0 || index >= list->size) {
        return NULL;
    }

    // 核心逻辑
    sl_node *node = list->head;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    return node;
}

static sl_node *sl_list_remove_only_one(sl_list *list) {
    sl_node *node = list->head;
    list->head = list->tail = NULL;
    list->size--;
    return node;
}

// 从头部删除节点
sl_node *sl_list_remove_front(sl_list *list) {
    // 链表为空或者NULL的情况
    if (!list || list->head == NULL) {
        return NULL;
    }
    // 链表只有一个节点的情况
    if (list->head == list->tail) {
        return sl_list_remove_only_one(list);
    }

    // 核心逻辑
    sl_node *node = list->head;
    list->head = list->head->next;
    list->size--;
    return node;
}

// 从尾部删除节点
sl_node *sl_list_remove_back(sl_list *list) {
    // 链表为空或者NULL的情况
    if (!list || list->head == NULL) {
        return NULL;
    }
    // 链表只有一个节点的情况
    if (list->head == list->tail) {
        return sl_list_remove_only_one(list);
    }

    // 快慢指针算法
    sl_node *p_slow = list->head;
    sl_node *p_fast = list->head->next;
    while (p_fast && p_fast->next != NULL) {
        p_fast = p_fast->next;
        p_slow = p_slow->next;
    }
    p_slow->next = NULL;
    list->size--;
    return p_fast;
}

// 从指定节点处删除
sl_node *sl_list_remove(sl_list *list, const int index) {
    // 链表为空或者NULL的情况
    if (!list || index < 0 || index >= list->size) {
        return NULL;
    }
    // 等同于从头部删除
    if (index == 0) {
        return sl_list_remove_front(list);
    }
    // 等同于从尾部删除
    if (index == list->size - 1) {
        return sl_list_remove_back(list);
    }

    // 核心逻辑
    sl_node *node = list->head;
    for (int i = 0; i < index - 1; i++) {
        node = node->next;
    }
    sl_node *p = node->next;
    node->next = p->next;
    list->size--;
    return p;
}

// 回收单向链表
void sl_list_destroy(sl_list *list) {
    if (!list) return;
    sl_node *p = list->head;
    // 释放节点
    while (p) {
        sl_node *next = p->next;
        free(p);
        p = next;
    }
    // 释放链表
    free(list);
}