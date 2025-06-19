#include <stdio.h>
#include <ex.h>

int main(void) {
    const int array[] = {1, 3, -1, -3, 5, 3, 6, 7};
    const int len = sizeof(array) / sizeof(array[0]);
    const int k = 3;
    const int *result = max_sliding_window(array, sizeof(array) / sizeof(int), k);
    for (int i = 0; i < len - k + 1; i++) {
        printf("%d ", result[i]);
    }
    return 0;
}
