//
// Created by admin on 25-6-19.
//
#include <deque.h>
#include <stdlib.h>

#include <ex.h>

// 滑动窗口最大值
int *max_sliding_window(int *arr, const int len, const int k) {
    int index = 0;
    if (len == 0 || k == 0) {
        return NULL;
    }

    int* result = malloc(sizeof(int) * (len - k + 1));

    deque* dq = deque_create();

    for (int i = 0; i < len; ++i) {
        if (dq->size > 0) {
            const int *front = deque_front(dq)->data;
            const int *back = deque_back(dq)->data;

            while (*front <= arr[i - k]) {
                deque_pop_front(dq);
                front = deque_front(dq)->data;
            }

            while (*back < arr[i]) {
                deque_pop_back(dq);
                back = deque_back(dq)->data;
            }
        }

        deque_push_back(dq, &arr[i]);

        if (i >= k - 1) {
            const int *front = deque_front(dq)->data;
            result[index++] = *front;
        }
    }

    deque_destroy(dq);
    return result;
}