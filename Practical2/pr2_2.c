// Write a Program
// ii) To search the element in 2-D array.


#include <stdio.h>

int main () {

    int arr[10][10];
    int rows, cols, i, j, num, found = 0;


    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);


    printf("Enter the elements of the 2-D array:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }


    printf("Enter the number to search in matrix: ");
    scanf("%d", &num);


    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (arr[i][j] == num) {
                printf("Element %d found at position (%d, %d)\n", num, i, j);
                found = 1;
            }
        }
    }


    if (!found) {
        printf("Element %d not found in the matrix.\n", num);
    }

    return 0;

}