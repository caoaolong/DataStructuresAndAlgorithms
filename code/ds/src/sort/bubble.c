//
// Created by admin on 25-6-20.
//

void bubble_sort(int* arr, const int len) {
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                const int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}