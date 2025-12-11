#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) return i; // found, return index
    }
    return -1; // not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5, key, result;

    printf("Enter element to search: ");
    scanf("%d", &key);

    result = linearSearch(arr, n, key);

    if(result != -1)
        printf("%d found at index %d\n", key, result);
    else
        printf("%d not found in array\n", key);

    return 0;
}