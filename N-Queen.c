#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 20  // Assuming maximum board size

int board[MAX_SIZE][MAX_SIZE];

bool isSafe(int board[MAX_SIZE][MAX_SIZE], int row, int col, int n) {
    int i, j;
    
    // Check the row on the left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueensUtil(int board[MAX_SIZE][MAX_SIZE], int col, int n) {
    if (col >= n)
        return true;
    
    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;
            if (solveNQueensUtil(board, col + 1, n))
                return true;
            board[i][col] = 0;  // backtrack
        }
    }
    return false;
}

void printBoard(int board[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

int main() {
    int N;
    printf("Enter the size of the board (N): ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    if (solveNQueensUtil(board, 0, N))
        printBoard(board, N);
    else
        printf("Solution does not exist\n");
    
    return 0;
}
