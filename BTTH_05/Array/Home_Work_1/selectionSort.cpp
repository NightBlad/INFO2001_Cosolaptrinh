#include <stdio.h>
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void selectionSort(int arr[], int n) {
    int i, j, min_index;
    for (i = 0; i < n - 1; i++) {
        min_index = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }swap(&arr[min_index], &arr[i]);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }printf("\n");
}
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 43, 45 ,89};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Mang truoc khi sap xep (Selection Sort): ");
    printArray(arr, n);
    selectionSort(arr, n);
    printf("Mang sau khi sap xep (Selection Sort): ");
    printArray(arr, n);
    return 0;
}

