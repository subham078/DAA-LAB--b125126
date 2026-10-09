//q.1.

#include <stdio.h>
#define MAX 100
int main(void) {
    int n, i, j;
    double W, time = 0, totalValue = 0;
    double v[MAX], w[MAX], lambda[MAX], taken[MAX];
    double density[MAX], temp;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter knapsack capacity: ");
    scanf("%lf", &W);
    for (i = 0; i < n; i++) {
        printf("Enter value, weight, decay rate: ");
        scanf("%lf %lf %lf", &v[i], &w[i], &lambda[i]);
        density[i] = v[i] / w[i];
        taken[i] = 0;
    }
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (density[j] > density[i]) {
                temp = density[i];
                density[i] = density[j];
                density[j] = temp;
                temp = v[i]; v[i] = v[j]; v[j] = temp;
                temp = w[i]; w[i] = w[j]; w[j] = temp;
                temp = lambda[i];
                lambda[i] = lambda[j]; lambda[j] = temp;
            }
        }
    }
    for (i = 0; i < n && W > 0; i++) {
        double adjusted = density[i] - lambda[i] * time;
        double amount = (w[i] < W) ? w[i] : W;

        if (adjusted > 0) {
            taken[i] = amount / w[i];
            totalValue += amount * adjusted;
            W -= amount;
            time += amount;
        }
    }
    printf("Estimated total value = %.2f\n", totalValue);
    printf("Remaining capacity = %.2f\n", W);
    return 0;
}