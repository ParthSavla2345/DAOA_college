#include <stdio.h>
#include <math.h>

int board[20], n;

int place(int row, int col) {
    for (int i = 1; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

void printBoard(int n) {
    printf("\nSolution:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i] == j)
                printf(" Q ");
            else
                printf(" - ");
        }
        printf("\n");
    }
}

void Queen(int row, int n) {
    for (int col = 1; col <= n; col++) {
        if (place(row, col)) {
            board[row] = col;
            if (row == n)
                printBoard(n);
            else
                Queen(row + 1, n);
        }
    }
}

int main() {
    printf("Enter the number of Queens: ");
    scanf("%d", &n);

    if (n == 2 || n == 3)
        printf("No solution exists for %d Queens.\n", n);
    else
        Queen(1, n);

    return 0;
}
