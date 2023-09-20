#include <stdio.h>

void readMatrix(int matrix[][10], int rows, int columns) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}


void displayMatrix(int matrix[][10], int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}


void multiplyMatrices(int A[][10], int B[][10], int C[][10], int rows1, int columns1, int columns2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < columns1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}


void addMatrices(int A[][10], int B[][10], int C[][10], int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}


int isMagicSquare(int square[][10], int size) {
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < size; i++) {
        sum1 += square[i][i];
        sum2 += square[i][size - i - 1];
    }
    if (sum1 != sum2) {
        return 0;
    }

    for (int i = 0; i < size; i++) {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < size; j++) {
            rowSum += square[i][j];
            colSum += square[j][i];
        }
        if (rowSum != sum1 || colSum != sum1) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int choice;
    int A[10][10], B[10][10], C[10][10];
    int rows1, columns1, rows2, columns2;

    printf("Enter the number of rows and columns of matrix A: ");
    scanf("%d %d", &rows1, &columns1);
    readMatrix(A, rows1, columns1);

    printf("Enter the number of rows and columns of matrix B: ");
    scanf("%d %d", &rows2, &columns2);
    readMatrix(B, rows2, columns2);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Multiply two matrices\n");
        printf("2. Add two matrices\n");
        printf("3. Check if a square matrix is a magic square\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (columns1 != rows2) {
                    printf("Matrix multiplication not possible. Number of columns in A must be equal to the number of rows in B.\n");
                } else {
                    multiplyMatrices(A, B, C, rows1, columns1, columns2);
                    printf("Result of matrix multiplication:\n");
                    displayMatrix(C, rows1, columns2);
                }
                break;
            case 2:
                if (rows1 != rows2 || columns1 != columns2) {
                    printf("Matrix addition not possible. Matrices must have the same dimensions.\n");
                } else {
                    addMatrices(A, B, C, rows1, columns1);
                    printf("Result of matrix addition:\n");
                    displayMatrix(C, rows1, columns1);
                }
                break;
            case 3:
                if (rows1 != columns1) {
                    printf("Matrix is not square. Cannot check if it's a magic square.\n");
                } else {
                    if (isMagicSquare(A, rows1)) {
                        printf("The matrix is a magic square.\n");
                    } else {
                        printf("The matrix is not a magic square.\n");
                    }
                }
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
