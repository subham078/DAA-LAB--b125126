#include <stdio.h>

typedef struct {
    int min;
    int max;
} Result;

Result maxMin(int a[], int low, int high) {

    Result result, leftResult, rightResult;

    // Only one element
    if (low == high) {
        result.min = a[low];
        result.max = a[low];

        return result;
    }

    // Two elements
    if (high == low + 1) {

        if (a[low] < a[high]) {
            result.min = a[low];
            result.max = a[high];
        }
        else {
            result.min = a[high];
            result.max = a[low];
        }

        return result;
    }

    int mid = (low + high) / 2;

    leftResult = maxMin(a, low, mid);
    rightResult = maxMin(a, mid + 1, high);

    if (leftResult.min < rightResult.min)
        result.min = leftResult.min;
    else
        result.min = rightResult.min;

    if (leftResult.max > rightResult.max)
        result.max = leftResult.max;
    else
        result.max = rightResult.max;

    return result;
}

int main() {

    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    Result answer = maxMin(a, 0, n - 1);

    printf("Minimum = %d\n", answer.min);
    printf("Maximum = %d\n", answer.max);

    return 0;
}