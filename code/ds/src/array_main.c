#include <stdio.h>
#include <array.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

static void foreach (const array *array)
{
    // 遍历
    printf("list(%llu): ", array->size);
    for (int i = 0; i < array->size; i++) {
        printf("%lld ", array->data[i]);
    }
    printf("\n");
}

void test() {
    array *array = array_create();
    // 尾部插入
    for (int i = 0; i < 10; i++)
    {
        array_insert_back(array, i);
    }
    foreach (array)
        ;
    // 头部插入
    for (int i = 0; i < 10; i++)
    {
        array_insert_front(array, i);
    }
    foreach (array)
        ;
    // 中间插入
    for (int i = 0; i < 10; i++)
    {
        const int value = rand() % 100;
        const int index = rand() % array->size;
        array_insert(array, index, value);
    }
    foreach (array)
        ;
    // 首部删除
    for (int i = 0; i < 5; i++)
    {
        const int64_t data = array_remove_front(array);
        printf("removed %lld\n", data);
    }
    foreach (array)
        ;
    // 尾部删除
    for (int i = 0; i < 5; i++)
    {
        const int64_t data = array_remove_back(array);
        printf("removed %lld\n", data);
    }
    foreach (array)
        ;
    // 中间删除
    for (int i = 0; i < 5; i++)
    {
        const int index = rand() % array->size;
        const int64_t data = array_remove(array, index);
        printf("removed %lld\n", data);
    }
    foreach (array)
        ;
    array_destroy(array);
}

int main(void) {
    array *array = array_create();
    FILE *file = fopen("../charts/array_insert.csv", "w+");
    for (int i = 0; i < 10000; i++) {
        const clock_t begin = clock();
        for (int j = 0; j < 100000; j++) {
            array_insert_back(array, j);
        }
        const clock_t end = clock();
        fprintf(file, "%llu\t%u\n", array->size, end - begin);
    }
    fclose(file);
    array_destroy(array);
    return 0;
}
