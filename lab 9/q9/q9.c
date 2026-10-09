//q.9.Hu–Tucker Greedy Simulation


#include <stdio.h>
#include <limits.h>

#define MAX 100

long long weight[MAX];
long long prefix[MAX];
long long dp[MAX][MAX];
int split[MAX][MAX];

long long sum(int i, int j) {
    return prefix[j + 1] - prefix[i];
}

void printTree(int i, int j) {
    if (i == j) {
        printf("Leaf%d ", i + 1);
        return;
    }

    printf("(");
    printTree(i, split[i][j]);
    printTree(split[i][j] + 1, j);
    printf(")");
}

int main(void) {
    int n, i, j, k, length;

    printf("Enter number of weights: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of weights.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        scanf("%lld", &weight[i]);

        if (weight[i] <= 0) {
            printf("Weights must be positive.\n");
            return 1;
        }

        prefix[i] = weight[i];
        if (i > 0)
            prefix[i] += prefix[i - 1];

        dp[i][i] = 0;
    }

    for (length = 2; length <= n; length++) {
        for (i = 0; i + length <= n; i++) {
            j = i + length - 1;
            dp[i][j] = LLONG_MAX;

            for (k = i; k < j; k++) {
                long long cost = dp[i][k] + dp[k + 1][j]
                               + sum(i, j);

                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    split[i][j] = k;
                }
            }
        }
    }

    printf("Minimum weighted path length = %lld\n", dp[0][n - 1]);
    printf("Optimal alphabetic tree: ");
    printTree(0, n - 1);
    printf("\n");

    return 0;
}