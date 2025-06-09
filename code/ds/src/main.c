#include <stdio.h>
#include <dl_list.h>

int main(void) {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    dl_list *list = dl_list_create();
    for (int i = 0; i < 10; i++) {
        dl_node *node = dl_node_create(&array[i]);
        dl_list_insert_front(list, node);
    }

    for (int i = 0; i < 10; i++) {
        dl_node *node = dl_node_create(&array[i]);
        dl_list_insert_back(list, node);
    }

    int value = 20;
    dl_node *node = dl_node_create(&value);
    dl_list_insert(list, 3, node);

    const dl_node *p = list->head;
    while (p != NULL) {
        const int *data = p->data;
        printf("%d ", *data);
        p = p->next;
    }
    printf("\n");
    return 0;
}