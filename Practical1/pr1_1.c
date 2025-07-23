// a) To traverse elements of an array.

#include <stdio.h>

int main () {

    int arr[5] = {1, 2, 3, 4, 5};
    int i;

    printf("Array elements are:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}