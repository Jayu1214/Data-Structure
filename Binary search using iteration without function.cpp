#include <stdio.h>
int main() {
    int a[] = {5,6,7,8,9,10};
    int n = sizeof(a) / sizeof(a[0]);
    int key = 10;
	int l = 0;
    int h = n - 1;
    int result = -1;
	while (l <= h) {
        int mid = l + (h - l) / 2;
		if (a[mid] == key) {
            result = mid;
            break;
        }
        else if (a[mid] > key) {
            h = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
	if (result != -1) {
        printf("Element %d found at index %d\n", key, result);
    } else {
        printf("Element not found in the array\n");
    }
	return 0;
}

