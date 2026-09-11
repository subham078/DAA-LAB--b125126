/* Q3. Reve's Puzzle - 4 Peg Tower of Hanoi */

#include <stdio.h>

#define MAX 30

long long dp[MAX];

long long hanoi3(int n) {
    if (n == 0)
        return 0;

    return 2 * hanoi3(n - 1) + 1;
}

void move3(int n, char from, char to, char aux) {
    if (n == 0)
        return;

    move3(n - 1, from, aux, to);

    printf("Move disk %d from %c to %c\n", n, from, to);

    move3(n - 1, aux, to, from);
}

void reve(int n, char from, char to, char aux1, char aux2) {
    if (n == 0)
        return;

    int k = 0;
    long long best = 999999999;

    for (int i = 1; i < n; i++) {
        long long moves = 2 * dp[i] + hanoi3(n - i);

        if (moves < best) {
            best = moves;
            k = i;
        }
    }

    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }

    reve(k, from, aux1, to, aux2);

    move3(n - k, from, to, aux2);

    reve(k, aux1, to, from, aux2);
}

int main() {
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i < n; i++) {
        dp[i] = 999999999;

        for (int k = 1; k < i; k++) {
            long long moves = 2 * dp[k] + hanoi3(i - k);

            if (moves < dp[i])
                dp[i] = moves;
        }
    }

    printf("\nMinimum moves = %lld\n\n", dp[n]);

    reve(n, 'A', 'D', 'B', 'C');

    return 0;
}