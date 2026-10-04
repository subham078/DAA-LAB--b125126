//q.8.Optimal Binary Search Tree (OBST)

#include <stdio.h>
#include <float.h>

#define MAX 101

int main() {
    int n;
    double p[MAX], q[MAX];
    double e[MAX][MAX], w[MAX][MAX];
    int root[MAX][MAX];

    printf("Enter number of keys: ");
    scanf("%d", &n);

    printf("Enter successful probabilities p[1..n]:\n");
    for (int i = 1; i <= n; i++)
        scanf("%lf", &p[i]);

    printf("Enter unsuccessful probabilities q[0..n]:\n");
    for (int i = 0; i <= n; i++)
        scanf("%lf", &q[i]);

    for (int i = 1; i <= n + 1; i++) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    for (int len = 1; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;

            e[i][j] = DBL_MAX;
            w[i][j] = w[i][j - 1] + p[j] + q[j];

            for (int r = i; r <= j; r++) {
                double cost = e[i][r - 1] +
                              e[r + 1][j] + w[i][j];

                if (cost < e[i][j]) {
                    e[i][j] = cost;
                    root[i][j] = r;
                }
            }
        }
    }

    printf("Minimum expected search cost = %.4lf\n", e[1][n]);
    printf("Root key index = %d\n", root[1][n]);

    return 0;
}