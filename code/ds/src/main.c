#include <stdio.h>
#include <sl_list.h>

int main(void) {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    sl_list *list = sl_list_create();
    for (int i = 0; i < 10; i++) {
        sl_node *node = sl_node_create(&array[i]);
        sl_list_insert_front(list, node);
    }

    for (int i = 0; i < 10; i++) {
        sl_node *node = sl_node_create(&array[i]);
        sl_list_insert_back(list, node);
    }

    sl_node *inode = sl_list_node(list, 3);
    int value = 20;
    sl_node *node = sl_node_create(&value);
    sl_list_insert(list, inode, node);

    const sl_node *p = list->head;
    while (p != NULL) {
        const int *data = p->data;
        printf("%d ", *data);
        p = p->next;
    }
    printf("\n");
    return 0;
}