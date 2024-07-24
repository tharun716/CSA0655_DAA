#include <stdio.h>
#include <stdbool.h>

#define N 10 
void printBoard(int board[N][N], int n);
bool isSafe(int board[N][N], int row, int col, int n);
bool solveNQueensUtil(int board[N][N], int col, int n);
bool solveNQueens(int n);
void printBoard(int board[N][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", board[i][j] ? 'Q' : '-');
        }
        printf("\n");
    }
    printf("\n");
}
bool isSafe(int board[N][N], int row, int col, int n) {
    for (int i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}
bool solveNQueensUtil(int board[N][N], int col, int n) {
    if (col >= n) {
        printBoard(board, n);
        return true; 
    }
    bool res = false;
    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;
            res = solveNQueensUtil(board, col + 1, n) || res;
            board[i][col] = 0; 
        }
    }

    return res;
}
bool solveNQueens(int n) {
    int board[N][N] = { {0} };

    if (!solveNQueensUtil(board, 0, n)) {
        printf("Solution does not exist for %d Queens problem.\n", n);
        return false;
    }

    return true;
}

int main() {
    int n;

    printf("Enter the number of Queens (max %d): ", N);
    scanf("%d", &n);

    if (n <= 0 || n > N) {
        printf("Invalid input! Please enter a number between 1 and %d.\n", N);
        return 1;
    }

    solveNQueens(n);

    return 0;
}
