#include <stdio.h>
#include <string.h>
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void bubbleSort(int arr[], int n) {
	int i,j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
void printArray(int arr[], int size) {
	int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 43, 45 ,89};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Mang truoc khi sap xep (Bubble Sort): ");
    printArray(arr, n);
    bubbleSort(arr, n);
    printf("Mang sau khi sap xep (Bubble Sort): ");
    printArray(arr, n);
    return 0;
}
