#include <stdio.h>
#include <stdlib.h>
void add(int **A, int **B, int **C, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] + B[i][j];
}
void subtract(int **A, int **B, int **C, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] - B[i][j];
}
int** allocateMatrix(int size) {
    int **matrix = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int *)malloc(size * sizeof(int));
    }
    return matrix;
}
void deallocateMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
void strassen(int **A, int **B, int **C, int size) {
    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    int newSize = size / 2;
    int **A11 = allocateMatrix(newSize);
    int **A12 = allocateMatrix(newSize);
    int **A21 = allocateMatrix(newSize);
    int **A22 = allocateMatrix(newSize);
    int **B11 = allocateMatrix(newSize);
    int **B12 = allocateMatrix(newSize);
    int **B21 = allocateMatrix(newSize);
    int **B22 = allocateMatrix(newSize);
    int **C11 = allocateMatrix(newSize);
    int **C12 = allocateMatrix(newSize);
    int **C21 = allocateMatrix(newSize);
    int **C22 = allocateMatrix(newSize);
    int **M1 = allocateMatrix(newSize);
    int **M2 = allocateMatrix(newSize);
    int **M3 = allocateMatrix(newSize);
    int **M4 = allocateMatrix(newSize);
    int **M5 = allocateMatrix(newSize);
    int **M6 = allocateMatrix(newSize);
    int **M7 = allocateMatrix(newSize);
    int **AResult = allocateMatrix(newSize);
    int **BResult = allocateMatrix(newSize);
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }
    add(A11, A22, AResult, newSize);
    add(B11, B22, BResult, newSize);
    strassen(AResult, BResult, M1, newSize);
    add(A21, A22, AResult, newSize);
    strassen(AResult, B11, M2, newSize);
    subtract(B12, B22, BResult, newSize);
    strassen(A11, BResult, M3, newSize);
    subtract(B21, B11, BResult, newSize);
    strassen(A22, BResult, M4, newSize);
    add(A11, A12, AResult, newSize);
    strassen(AResult, B22, M5, newSize);
    subtract(A21, A11, AResult, newSize);
    add(B11, B12, BResult, newSize);
    strassen(AResult, BResult, M6, newSize);
    subtract(A12, A22, AResult, newSize);
    add(B21, B22, BResult, newSize);
    strassen(AResult, BResult, M7, newSize);
    add(M1, M4, AResult, newSize);
    subtract(AResult, M5, BResult, newSize);
    add(BResult, M7, C11, newSize);
    add(M3, M5, C12, newSize);
    add(M2, M4, C21, newSize);
    subtract(M1, M2, AResult, newSize);
    add(AResult, M3, BResult, newSize);
    add(BResult, M6, C22, newSize);
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
    deallocateMatrix(A11, newSize);
    deallocateMatrix(A12, newSize);
    deallocateMatrix(A21, newSize);
    deallocateMatrix(A22, newSize);
    deallocateMatrix(B11, newSize);
    deallocateMatrix(B12, newSize);
    deallocateMatrix(B21, newSize);
    deallocateMatrix(B22, newSize);
    deallocateMatrix(C11, newSize);
    deallocateMatrix(C12, newSize);
    deallocateMatrix(C21, newSize);
    deallocateMatrix(C22, newSize);
    deallocateMatrix(M1, newSize);
    deallocateMatrix(M2, newSize);
    deallocateMatrix(M3, newSize);
    deallocateMatrix(M4, newSize);
    deallocateMatrix(M5, newSize);
    deallocateMatrix(M6, newSize);
    deallocateMatrix(M7, newSize);
    deallocateMatrix(AResult, newSize);
    deallocateMatrix(BResult, newSize);
}
void printMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int size;
    printf("Enter the size of the matrices (must be a power of 2): ");
    scanf("%d", &size);
    int **A = allocateMatrix(size);
    int **B = allocateMatrix(size);
    int **C = allocateMatrix(size);
    printf("Enter matrix A:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    printf("Enter matrix B:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    strassen(A, B, C, size);
    printf("Result matrix C:\n");
    printMatrix(C, size);
    deallocateMatrix(A, size);
    deallocateMatrix(B, size);
    deallocateMatrix(C, size);

    return 0;
}
