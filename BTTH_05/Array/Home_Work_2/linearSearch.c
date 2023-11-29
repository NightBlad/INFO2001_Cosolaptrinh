#include <stdio.h>

int linearSearch(int arr[], int n, int target) {
	int i; 
    for (i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i+1;  
        }
    }
    return -1;  
}

int main() {
    int arr[] = {4, 2, 7, 1, 9, 5, 3, 8, 6, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int result = linearSearch(arr, n, target);

    if (result != -1) {
        printf("Phan tu %d duoc tim thay tai vi tri %d.\n", target, result);
    } else {
        printf("Phan tu %d khong co trong mang.\n", target);
    }

    return 0;
}

