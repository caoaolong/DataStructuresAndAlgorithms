//
// Created by admin on 25-6-12.
//

#ifndef ARRAY_H
#define ARRAY_H

#include <stdint.h>

typedef struct array_t {
    void **data;     // 数据
    size_t size;     // 数量
    size_t capacity; // 容量
} array;

// 创建数组
array *array_create();

// 从头部插入
void array_insert_front(array *array, void *data);

// 从尾部插入
void array_insert_back(array *array, void *data);

// 从中间插入
void array_insert(array *array, int index, void *data);

// 获取节点
void *array_node(const array *array, int index);

// 从头部删除
void *array_remove_front(array *array);

// 从尾部删除
void *array_remove_back(array *array);

// 从中间删除
void *array_remove(array *array, int index);

// 释放数组
void array_destroy(const array *array);

#endif //ARRAY_H
