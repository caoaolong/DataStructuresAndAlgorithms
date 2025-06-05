//
// Created by admin on 25-6-5.
//
#include <ds_list.h>
#include <stdlib.h>

sl_list *sl_list_create() {
    sl_list *list = malloc(sizeof(sl_list));
    list->head = list->tail = NULL;
    list->size = 0;
    return list;
}

sl_node *sl_node_create(void *data) {
    sl_node *node = malloc(sizeof(sl_node));
    node->data = data;
    node->next = NULL;
    return node;
}

void sl_list_insert_front(sl_list *list, sl_node *node) {
    if (!list || !node) return;
    if (list->head == NULL) {
        list->head = list->tail = node;
        list->size++;
        return;
    }
    node->next = list->head;
    list->head = node;
    list->size++;
}

void sl_list_insert_back(sl_list *list, sl_node *node) {
    if (!list || !node) return;
    if (list->head == NULL) {
        list->head = list->tail = node;
        list->size++;
        return;
    }
    list->tail->next = node;
    list->tail = node;
    list->size++;
}

void sl_list_insert(sl_list *list, sl_node *inode, sl_node *node) {
    if (!list || !node) return;
    node->next = inode->next;
    inode->next = node;
    if (inode == list->tail) {
        list->tail = node;
    }
    list->size++;
}

sl_node *sl_list_node(const sl_list *list, const int index) {
    if (!list || index < 0 || index >= list->size) {
        return NULL;
    }
    sl_node *node = list->head;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    return node;
}

// 从头部删除节点
sl_node *sl_list_remove_front(sl_list *list) {
    if (!list || list->head == NULL) {
        return NULL;
    }
    sl_node *node = list->head;
    list->head = list->head->next;
    list->size--;
    return node;
}

// 从尾部删除节点
sl_node *sl_list_remove_back(sl_list *list) {
    if (!list || list->head == NULL) {
        return NULL;
    }
    if (list->head == list->tail) {
        sl_node *node = list->head;
        list->head = list->tail = NULL;
        list->size--;
        return node;
    }
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

sl_node *sl_list_remove(sl_list *list, const int index) {
    if (!list || index < 0 || index >= list->size) {
        return NULL;
    }
    if (index == 0) {
        return sl_list_remove_front(list);
    }
    if (index == list->size - 1) {
        return sl_list_remove_back(list);
    }
    sl_node *node = list->head;
    for (int i = 0; i < index - 1; i++) {
        node = node->next;
    }
    sl_node *p = node->next;
    node->next = node->next->next;
    list->size--;
    return p;
}

void sl_list_destroy(sl_list *list) {
    if (!list) return;
    sl_node *p = list->head;
    while (p) {
        sl_node *next = p->next;
        free(p);
        p = next;
    }
    free(list);
}