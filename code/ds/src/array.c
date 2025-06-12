//
// Created by admin on 25-6-12.
//
#include <array.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 创建数组
array *array_create() {
    array *arr = malloc(sizeof(array));
    arr->size = 0;
    arr->capacity = 8;
    arr->data = malloc(sizeof(void *) * arr->capacity);
    return arr;
}

static bool array_expand(array *arr) {
    if (!arr || !arr->data)
        return false;
    // 每次扩大到原来的两倍
    arr->capacity *= 2;
    void **data = realloc(arr->data, sizeof(void *) * arr->capacity);
    if (data) {
        arr->data = data;
        return true;
    }

    arr->capacity /= 2;
    fprintf(stderr, "array expand failed");
    return false;
}

static bool array_is_full(const array *arr) {
    return arr->size == arr->capacity;
}

// 从头部插入
void array_insert_front(array *array, void *data) {
    // 处理异常情况
    if (!array) return;
    // 判断是否需要扩容
    if (array_is_full(array))
        array_expand(array);

    // 等同于从中间插入
    array_insert_front(array, 0, data);
}

// 从尾部插入
void array_insert_back(array *array, void *data) {
    // 处理异常情况
    if (!array) return;
    // 判断是否需要扩容
    if (array_is_full(array))
        array_expand(array);

    // 核心逻辑
    array->data[array->size] = data;
    array->size++;
}

// 从中间插入
void array_insert_front(array *array, const int index, void *data) {
    // 处理异常情况
    if (!array) return;
    // 判断是否需要扩容
    if (array_is_full(array))
        array_expand(array);

    // 核心逻辑
    for (size_t i = array->size; i > index; i--) {
        array->data[i] = array->data[i - 1];
    }
    array->data[index] = data;
    array->size++;
}

// 获取节点
void *array_node(const array *array, const int index) {
    // 处理异常情况
    if (!array) return NULL;

    // 核心逻辑
    return array->data[index];
}

// 从头部删除
void *array_remove_front(array *array) {
    // 处理异常情况
    if (!array) return NULL;

    // 等同于从中间删除
    return array_remove(array, 0);
}

// 从尾部删除
void *array_remove_back(array *array) {
    // 处理异常情况
    if (!array) return NULL;

    // 核心逻辑
    void *data = array->data[array->size - 1];
    array->size--;
    return data;
}

// 从中间删除
void *array_remove(array *array, const int index) {
    // 处理异常情况
    if (!array) return NULL;

    // 核心逻辑
    void *data = array->data[array->size - 1];
    for (size_t i = index; i <  array->size; i++) {
        array->data[i] = array->data[i + 1];
    }
    array->size--;
    return data;
}

// 释放数组
void array_destroy(const array *array) {
    if (!array) return;

    for (int i = 0; i < array->size; i++) {
        free(array->data[i]);
    }
    free(array->data);
}
