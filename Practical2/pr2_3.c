// Write a program
// iii) To create, initialize and print the values of the 3-D array.


# include <stdio.h>

int main () {

    int arr[2][2][2];
    int i, j, k;


    printf("Enter 8 elements for the 3-D array:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 2; k++) {
                printf("Element at [%d][%d][%d]: ", i, j, k);
                scanf("%d", &arr[i][j][k]);
            }
        }
    }

    printf("\n3-D Array Elements:\n");
    for (i = 0; i < 2; i++) {
        printf("Layer %d:\n", i);
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 2; k++) {
                printf("%d ", arr[i][j][k]);
            }  
            printf("\n");     
    }
    printf("\n");
}

return 0;

}