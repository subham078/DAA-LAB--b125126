

/* Q2. Super Egg Testing Experiment */

#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int E, F;
    printf("Enter number of eggs and floors: ");
    scanf("%d %d", &E, &F);

    int dp[E + 1][F + 1];

    for (int e = 1; e <= E; e++) {
        dp[e][0] = 0;
        dp[e][1] = 1;
    }

    for (int f = 0; f <= F; f++)
        dp[1][f] = f;

    for (int e = 2; e <= E; e++) {
        for (int f = 2; f <= F; f++) {
            dp[e][f] = 999999;

            for (int x = 1; x <= f; x++) {
                int attempts = 1 + max(dp[e - 1][x - 1],
                                       dp[e][f - x]);

                if (attempts < dp[e][f])
                    dp[e][f] = attempts;
            }
        }
    }

    printf("Minimum droppings = %d\n", dp[E][F]);

    return 0;
}