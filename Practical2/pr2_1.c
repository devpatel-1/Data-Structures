// Write a Program
// i) To implement an Array representation of the sparse matrices.




// What is a sparce matrix?

// A sparce matrix is a matrix with most of its elements as 0.
// Instead of storing all elements, we store only non-zero elements in a compact form.


// Each non-zero element is stored as a triplet (row, column, value).


#include <stdio.h>

#define MAX 100

int main () {

    int matrix[10][10];
    int sparse[100][3];
    int row, col, i, j, k = 1, nonZero = 0;

    printf("Enter rows and columns: ");
    scanf("%d %d", &row, &col);


    printf("Enter the matrix elements:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &matrix[i][j]);

            if (matrix[i][j] != 0) {
                sparse[k][0] = i; // row index
                sparse[k][1] = j; // column index
                sparse[k][2] = matrix[i][j]; // value
                k++;
                nonZero++;
            }
        }
    }

    sparse[0][0] = row; // total rows
    sparse[0][1] = col; // total columns
    sparse[0][2] = nonZero; // number of non-zero elements

    printf("\nSparse Matrix Representation:\n");
    printf("Row\tColumn\tValue\n");
    for (i = 0; i <= nonZero; i++) {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
    
    return 0;

}