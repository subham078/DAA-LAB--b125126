//q.6.Edit Distance with Traceback Information

#include <stdio.h>
#include <string.h>

int main() {
    char A[101], B[101];
    int dp[101][101];

    printf("Enter first string: ");
    scanf("%100s", A);

    printf("Enter second string: ");
    scanf("%100s", B);

    int m = strlen(A);
    int n = strlen(B);

    for (int i = 0; i <= m; i++)
        dp[i][0] = i;

    for (int j = 0; j <= n; j++)
        dp[0][j] = j;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int cost = (A[i - 1] == B[j - 1]) ? 0 : 1;

            int del = dp[i - 1][j] + 1;
            int ins = dp[i][j - 1] + 1;
            int sub = dp[i - 1][j - 1] + cost;

            dp[i][j] = del < ins ? del : ins;
            if (sub < dp[i][j])
                dp[i][j] = sub;
        }
    }

    char alignA[201], alignB[201];
    int i = m, j = n, k = 0;

    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 &&
            dp[i][j] == dp[i - 1][j - 1] +
            (A[i - 1] == B[j - 1] ? 0 : 1)) {
            alignA[k] = A[i - 1];
            alignB[k] = B[j - 1];
            i--;
            j--;
        } else if (i > 0 && dp[i][j] == dp[i - 1][j] + 1) {
            alignA[k] = A[i - 1];
            alignB[k] = '-';
            i--;
        } else {
            alignA[k] = '-';
            alignB[k] = B[j - 1];
            j--;
        }
        k++;
    }

    printf("Minimum edit distance = %d\n", dp[m][n]);

    printf("Traceback alignment:\n");
    for (int t = k - 1; t >= 0; t--)
        printf("%c", alignA[t]);
    printf("\n");

    for (int t = k - 1; t >= 0; t--)
        printf("%c", alignB[t]);
    printf("\n");

    return 0;
}