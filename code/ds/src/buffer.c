//
// Created by admin on 25-6-17.
//
#include <buffer.h>
#include <stdlib.h>

// 创建缓冲
buffer *buffer_create() {
    buffer *buf = malloc(sizeof(buffer));
    buf->data = array_create();
    buf->read = buf->write = 0;
    return buf;
}

// 重置缓冲的读写指针
void buffer_reset(buffer *buffer) {
    buffer->read = buffer->write = 0;
}

// 向缓冲中写入数据
void buffer_write(buffer *buffer, void *data) {
    array_insert_back(buffer->data, data);
    buffer->write++;
}

// 从缓冲中读取数据
void *buffer_read(buffer *buffer) {
    if (buffer->read >= buffer->write) {
        return NULL;
    }
    return array_node(buffer->data, buffer->read++);
}

// 释放缓冲
void buffer_destroy(buffer *buffer) {
    array_destroy(buffer->data);
    free(buffer);
}