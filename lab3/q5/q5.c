#include <stdio.h>

#define MAX 64

void specialMultiply(int A[MAX][MAX],
                     int B[MAX][MAX],
                     int C[MAX][MAX],
                     int n) {

    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    int A1[MAX][MAX], A2[MAX][MAX];
    int B1[MAX][MAX], B2[MAX][MAX];

    int X[MAX][MAX], Y[MAX][MAX];
    int Z[MAX][MAX], W[MAX][MAX];

    // Extract blocks
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {

            A1[i][j] = A[i][j];
            A2[i][j] = A[i][j + k];

            B1[i][j] = B[i][j];
            B2[i][j] = B[i][j + k];
        }
    }

    // Four recursive multiplications
    specialMultiply(A1, B1, X, k);
    specialMultiply(A2, B2, Y, k);

    specialMultiply(A1, B2, Z, k);
    specialMultiply(A2, B1, W, k);

    // Construct C
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {

            int C1 = X[i][j] + Y[i][j];
            int C2 = Z[i][j] + W[i][j];

            C[i][j] = C1;
            C[i][j + k] = C2;

            C[i + k][j] = C2;
            C[i + k][j + k] = C1;
        }
    }
}

int main() {

    int n;
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    printf("Enter n (power of 2): ");
    scanf("%d", &n);

    printf("Enter matrix A:\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter matrix B:\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    specialMultiply(A, B, C, n);

    printf("\nResult:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", C[i][j]);

        printf("\n");
    }

    return 0;
}