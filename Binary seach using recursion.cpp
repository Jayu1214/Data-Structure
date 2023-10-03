#include <stdio.h>
int binarySearchRecursive(int arr[], int l, int h, int key) {
    if (l <= h) {
        int mid = l + (h - l) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] > key) {
            return binarySearchRecursive(arr, l, mid - 1, key);
        }
        else {
            return binarySearchRecursive(arr, mid + 1, h, key);
        }
    }
    return -1;
}

int main() {
    int arr[] = {5,6,7,8,9,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;

    int result = binarySearchRecursive(arr, 0, n - 1, key);

    if (result != -1) {
        printf("Element %d found at index %d\n", key, result);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}

