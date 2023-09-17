#include "bubble_sort.h"

void swap(char **xp, char **yp) {
    char *temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(char **arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
