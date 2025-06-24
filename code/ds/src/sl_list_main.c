#include <stdio.h>
#include <sl_list.h>
#include <stdlib.h>
#include <time.h>

static void foreach (const sl_list *list)
{
    // 遍历
    printf("list(%llu): ", list->size);
    const sl_node *pn = list->head;
    while (pn)
    {
        printf("%lld ", pn->data);
        pn = pn->next;
    }
    printf("\n");
}

void test() {
    sl_list *list = sl_list_create();
    // 尾部插入
    for (int i = 0; i < 10; i++)
    {
        sl_list_insert_back(list, sl_node_create(i + 1));
    }
    foreach (list)
        ;
    // 头部插入
    for (int i = 0; i < 10; i++)
    {
        sl_list_insert_front(list, sl_node_create(i + 1));
    }
    foreach (list)
        ;
    // 中间插入
    for (int i = 0; i < 10; i++)
    {
        const int value = rand() % 100;
        const int index = rand() % list->size;
        sl_list_insert(list, index, sl_node_create(value));
    }
    foreach (list)
        ;
    // 首部删除
    for (int i = 0; i < 5; i++)
    {
        const sl_node *node = sl_list_remove_front(list);
        printf("removed %lld\n", node->data);
    }
    foreach (list)
        ;
    // 尾部删除
    for (int i = 0; i < 5; i++)
    {
        const sl_node *node = sl_list_remove_back(list);
        printf("removed %lld\n", node->data);
    }
    foreach (list)
        ;
    // 中间删除
    for (int i = 0; i < 5; i++)
    {
        const int index = rand() % list->size;
        const sl_node *node = sl_list_remove(list, index);
        printf("removed %lld\n", node->data);
    }
    foreach (list)
        ;
    sl_list_destroy(list);
}

int main(void) {
    sl_list *list = sl_list_create();
    const int init_size = 100000;
    for (int i = 0; i < init_size; i++) {
        sl_node *node = sl_node_create(i);
        sl_list_insert_back(list, node);
    }
    FILE *file = fopen("../charts/sl_list_query.csv", "w+");
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 5000; j++) {
            sl_node *node = sl_node_create(i);
            node->value = i * 1000 + j;
            sl_list_insert_back(list, node);
        }
        const clock_t begin = clock();
        sl_list_node(list, (int)list->size - 1);
        const clock_t end = clock();
        fprintf(file, "%d\t%u\n", (int)list->size - init_size, end - begin);
    }
    fclose(file);
    sl_list_destroy(list);
    return 0;
}
