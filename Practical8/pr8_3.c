#include <stdio.h>
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for(i = 0; i < n-1; i++) {
        min_idx = i;
        for(j = i+1; j < n; j++)
            if(arr[j] < arr[min_idx])
                min_idx = j;
        temp = arr[min_idx]; arr[min_idx] = arr[i]; arr[i] = temp;
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11}, i;
    int n = 5;
    selectionSort(arr, n);
    printf("Sorted array: ");
    for(i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}