#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n-1, mid;

    while(low <= high) {
        mid = low + (high - low) / 2;
        if(arr[mid] == key) return mid;       // found
        else if(arr[mid] < key) low = mid+1; // search right half
        else high = mid-1;                    // search left half
    }
    return -1; // not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5, key, result;

    printf("Enter element to search: ");
    scanf("%d", &key);

    result = binarySearch(arr, n, key);

    if(result != -1)
        printf("%d found at index %d\n", key, result);
    else
        printf("%d not found in array\n", key);

    return 0;
}