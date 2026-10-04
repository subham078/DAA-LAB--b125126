//q.5.Maximum Sum Increasing Subsequence

#include <stdio.h>

int main() {
    int n;

    printf("Enter array size: ");
    scanf("%d", &n);

    int a[n], dp[n];

    printf("Enter positive elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        dp[i] = a[i];
    }

    int maxSum = dp[0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && dp[j] + a[i] > dp[i])
                dp[i] = dp[j] + a[i];
        }

        if (dp[i] > maxSum)
            maxSum = dp[i];
    }

    printf("Maximum sum = %d\n", maxSum);

    return 0;
}