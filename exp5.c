#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void LCS_Length(char *X, char *Y, int m, int n, int **c, char **b) {
    int i, j;

    for (i = 0; i <= m; i++)
        c[i][0] = 0;
    for (j = 0; j <= n; j++)
        c[0][j] = 0;

    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'D';  
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = 'U';  
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'L';  
            }
        }
    }
}

void Print_LCS(char **b, char *X, int i, int j) {
    if (i == 0 || j == 0)
        return;
    if (b[i][j] == 'D') {
        Print_LCS(b, X, i - 1, j - 1);
        printf("%c", X[i - 1]);
    } else if (b[i][j] == 'U') {
        Print_LCS(b, X, i - 1, j);
    } else {
        Print_LCS(b, X, i, j - 1);
    }
}

int main() {
    char X[100], Y[100];
    int m, n, i;

    printf("Enter first sequence: ");
    scanf("%s", X);
    printf("Enter second sequence: ");
    scanf("%s", Y);

    m = strlen(X);
    n = strlen(Y);

    int **c = (int **)malloc((m + 1) * sizeof(int *));
    char **b = (char **)malloc((m + 1) * sizeof(char *));
    for (i = 0; i <= m; i++) {
        c[i] = (int *)malloc((n + 1) * sizeof(int));
        b[i] = (char *)malloc((n + 1) * sizeof(char));
    }

    LCS_Length(X, Y, m, n, c, b);

    printf("\nLength of LCS: %d\n", c[m][n]);
    printf("Longest Common Subsequence: ");
    Print_LCS(b, X, m, n);
    printf("\n");

    for (i = 0; i <= m; i++) {
        free(c[i]);
        free(b[i]);
    }
    free(c);
    free(b);

    return 0;
}
