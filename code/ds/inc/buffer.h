//
// Created by admin on 25-6-17.
//

#ifndef BUFFER_H
#define BUFFER_H

#include <array.h>

typedef struct buffer_t {
    array *data;
    int read;
    int write;
} buffer;

// 创建缓冲
buffer *buffer_create();

// 重置缓冲的读写指针
void buffer_reset(buffer *buffer);

// 向缓冲中写入数据
void buffer_write(buffer *buffer, void *data);

// 从缓冲中读取数据
void *buffer_read(buffer *buffer);

// 释放缓冲
void buffer_destroy(buffer *buffer);

#endif //BUFFER_H
