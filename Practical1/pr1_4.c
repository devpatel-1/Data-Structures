// d) To find the minimum, maximum and average values of the given Array.

#include <stdio.h>

int main () {

    int arr[100], n, i;
    int min, max;
    float sum = 0, avg;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    min = max = arr[0];
    
    for (i = 0; i < n; i++){
        sum += arr[i];

        if (arr[i] < min) {
            min = arr[i];
        }

        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    avg = sum / n;

    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);
    printf("Average value: %.2f\n", avg);

    return 0;
}