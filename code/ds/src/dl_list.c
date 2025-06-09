//
// Created by admin on 25-6-9.
//
#include <dl_list.h>
#include <stdlib.h>

// 创建双向链表
dl_list *dl_list_create() {
    dl_list *list = malloc(sizeof(dl_list));
    list->head = list->tail = NULL;
    list->size = 0;
    return list;
}

// 创建双向链表节点
dl_node *dl_node_create(void *data) {
    dl_node *node = malloc(sizeof(dl_node));
    node->data = data;
    node->prev =node->next = NULL;
    return node;
}

// 从头部插入节点
void dl_list_insert_front(dl_list *list, dl_node *node) {
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
    list->head->prev = node;
    list->head = node;
    list->size++;
}

// 从尾部插入节点
void dl_list_insert_back(dl_list *list, dl_node *node) {
    // 链表为NULL的情况
    if (!list || !node) return;
    // 链表为空的情况
    if (list->head == NULL) {
        list->head = list->tail = node;
        list->size++;
        return;
    }

    // 核心逻辑
    node->prev = list->tail;
    list->tail->next = node;
    list->tail = node;
    list->size++;
}

// 从指定节点处插入节点
void dl_list_insert(dl_list *list, const int index, dl_node *node) {
    // 链表为NULL的情况
    if (!list || !node) return;
    // 等同于从头部插入
    if (index == 0) {
        dl_list_insert_front(list, node);
        return;
    }
    // 等同于从尾部插入
    if (index == list->size - 1) {
        dl_list_insert_back(list, node);
    }

    // 核心逻辑(可优化)
    /** 优化方案：
     *  根据index距离0和size-1的大小判断是从head开始索引还是从tail开始索引
     */
    dl_node *p = list->head;
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
dl_node *dl_list_node(const dl_list *list, const int index) {
    // 索引越界的情况
    if (!list || index < 0 || index >= list->size) {
        return NULL;
    }

    // 核心逻辑(可优化)
    /** 优化方案：
     *  根据index距离0和size-1的大小判断是从head开始索引还是从tail开始索引
     */
    dl_node *node = list->head;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    return node;
}

static dl_node *dl_list_remove_only_one(dl_list *list) {
    dl_node *node = list->head;
    list->head = list->tail = NULL;
    list->size--;
    return node;
}

// 从头部删除节点
dl_node *dl_list_remove_front(dl_list *list) {
    // 链表为空或者NULL的情况
    if (!list || list->head == NULL) {
        return NULL;
    }
    // 链表只有一个节点的情况
    if (list->head == list->tail) {
        return dl_list_remove_only_one(list);
    }

    // 核心逻辑
    dl_node *node = list->head;
    list->head = list->head->next;
    list->head->prev = NULL;
    list->size--;
    return node;
}

// 从尾部删除节点
dl_node *dl_list_remove_back(dl_list *list) {
    // 链表为空或者NULL的情况
    if (!list || list->head == NULL) {
        return NULL;
    }
    // 链表只有一个节点的情况
    if (list->head == list->tail) {
        return dl_list_remove_only_one(list);
    }

    // 核心逻辑
    dl_node *node = list->tail;
    list->tail = list->tail->prev;
    list->tail->next = NULL;
    list->size--;
    return node;
}

// 从指定节点处删除
dl_node *dl_list_remove(dl_list *list, const int index) {
    // 链表为空或者NULL的情况
    if (!list || index < 0 || index >= list->size) {
        return NULL;
    }
    // 等同于从头部删除
    if (index == 0) {
        return dl_list_remove_front(list);
    }
    // 等同于从尾部删除
    if (index == list->size - 1) {
        return dl_list_remove_back(list);
    }

    // 核心逻辑(可优化)
    /** 优化方案：
     *  根据index距离0和size-1的大小判断是从head开始索引还是从tail开始索引
     */
    dl_node *node = list->head;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    node->next->prev = node->prev;
    node->prev->next = node->next;
    list->size--;
    return node;
}

// 回收双向链表
void dl_list_destroy(dl_list *list) {
    if (!list) return;
    dl_node *p = list->head;
    while (p) {
        dl_node *next = p->next;
        free(p);
        p = next;
    }
    free(list);
}