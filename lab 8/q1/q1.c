//q.1. Minimum Coin Change

#include <stdio.h>
#include <limits.h>

int minCoins(int coins[], int n, int V) {
    int dp[V + 1];

    dp[0] = 0;

    for (int i = 1; i <= V; i++)
        dp[i] = INT_MAX;

    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                int candidate = dp[i - coins[j]] + 1;
                if (candidate < dp[i])
                    dp[i] = candidate;
            }
        }
    }

    return dp[V] == INT_MAX ? -1 : dp[V];
}

int main() {
    int n, V;

    printf("Enter number of coins: ");
    scanf("%d", &n);

    int coins[n];

    printf("Enter coin denominations: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &coins[i]);

    printf("Enter target amount: ");
    scanf("%d", &V);

    printf("Minimum coins = %d\n", minCoins(coins, n, V));

    return 0;
}