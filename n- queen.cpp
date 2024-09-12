#include <stdio.h>

#define N 4

int board[N][N];

void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

int isSafe(int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i]) return 0;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return 0;

    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j]) return 0;

    return 1;
}

int solveNQUtil(int col) {
    if (col >= N) return 1;

    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;
            if (solveNQUtil(col + 1)) return 1;
            board[i][col] = 0;
        }
    }
    return 0;
}

int main() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    if (solveNQUtil(0) == 0) {
        printf("Solution does not exist");
    } else {
        printSolution();
    }

    return 0;
}

