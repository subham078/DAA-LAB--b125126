//q.5.Candy Distribution Problem


#include <stdio.h>

#define MAX 1000

int main(void) {
    int n, rating[MAX], candy[MAX];
    int i, total = 0;

    printf("Enter number of children: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of children.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        scanf("%d", &rating[i]);
        candy[i] = 1;
    }

    for (i = 1; i < n; i++) {
        if (rating[i] > rating[i - 1])
            candy[i] = candy[i - 1] + 1;
    }

    for (i = n - 2; i >= 0; i--) {
        if (rating[i] > rating[i + 1] &&
            candy[i] <= candy[i + 1])
            candy[i] = candy[i + 1] + 1;
    }

    for (i = 0; i < n; i++) {
        total += candy[i];
    }

    printf("Candies given: ");
    for (i = 0; i < n; i++)
        printf("%d ", candy[i]);

    printf("\nMinimum total candies = %d\n", total);
    return 0;
}