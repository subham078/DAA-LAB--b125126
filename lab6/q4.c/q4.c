//q.4.Matrix Chain Multiplication using Dynamic Programming

#include <stdio.h>
#include <limits.h>

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int matrixChainMultiplication(int arr[], int n)
{
    int dp[n][n];

    // Cost is zero when multiplying one matrix
    for (int i = 1; i < n; i++)
    {
        dp[i][i] = 0;
    }

    // length is the chain length
    for (int length = 2; length < n; length++)
    {
        for (int i = 1; i < n - length + 1; i++)
        {
            int j = i + length - 1;

            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + arr[i - 1] * arr[k] * arr[j];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][n - 1];
}

int main()
{
    int n;

    printf("Enter N: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int result = matrixChainMultiplication(arr, n);

    printf("Minimum number of scalar multiplications = %d\n", result);

    return 0;
}