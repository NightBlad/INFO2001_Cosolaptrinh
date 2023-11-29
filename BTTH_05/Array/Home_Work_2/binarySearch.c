#include <stdio.h>
#include <string.h> 
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
int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;  
        } else if (arr[mid] < target) {
            low = mid + 1;  
        } else {
            high = mid - 1;  
        }
    }

    return -1; 
}

int main() {
    int arr[] = {10, 5, 4, 1, 8, 9, 2, 7, 6 ,3};
//    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
	selectionSort(arr, n);
    int result = binarySearch(arr, 0, n - 1, target) + 1;

    if (result != -1) {
        printf("Phan tu %d duoc tim thay tai vi tri %d.\n", target, result);
    } else {
        printf("Phan tu %d khong co trong mang.\n", target);
    }

    return 0;
}

