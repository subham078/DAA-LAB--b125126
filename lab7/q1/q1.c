/* Q1. Invert the Coin Triangle */

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int moves = (n * (n + 1)) / 6;

    printf("Minimum moves = %d\n", moves);

    return 0;
}
