//q.7.Rod Cutting with Reconstruction

#include <stdio.h>

int main() {
    int n;

    printf("Enter rod length: ");
    scanf("%d", &n);

    int price[n + 1];
    int dp[n + 1];
    int firstCut[n + 1];

    printf("Enter prices for lengths 1 to %d:\n", n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &price[i]);

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = price[i];
        firstCut[i] = i;

        for (int j = 1; j < i; j++) {
            if (price[j] + dp[i - j] > dp[i]) {
                dp[i] = price[j] + dp[i - j];
                firstCut[i] = j;
            }
        }
    }

    printf("Maximum revenue = %d\n", dp[n]);
    printf("Optimal pieces: ");

    int length = n;
    while (length > 0) {
        printf("%d ", firstCut[length]);
        length -= firstCut[length];
    }

    printf("\n");

    return 0;
}