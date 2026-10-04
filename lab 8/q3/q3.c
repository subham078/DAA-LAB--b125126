//q.3.Longest Common Subsequence (LCS)

#include <stdio.h>
#include <string.h>

int main() {
    char X[100], Y[100];
    int dp[101][101];

    printf("Enter first string: ");
    scanf("%99s", X);

    printf("Enter second string: ");
    scanf("%99s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    for (int i = 0; i <= m; i++)
        dp[i][0] = 0;

    for (int j = 0; j <= n; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else if (dp[i - 1][j] >= dp[i][j - 1])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i][j - 1];
        }
    }

    char lcs[101];
    int i = m, j = n, k = dp[m][n];

    lcs[k] = '\0';

    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[--k] = X[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("LCS length = %d\n", dp[m][n]);
    printf("LCS = %s\n", lcs);

    return 0;
}