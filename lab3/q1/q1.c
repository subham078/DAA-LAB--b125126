#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int a[], int n, int x, int *comparisons) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        (*comparisons)++;

        if (a[mid] == x)
            return mid;

        if (a[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int ternarySearch(int a[], int n, int x, int *comparisons) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int third = (high - low) / 3;

        int mid1 = low + third;
        int mid2 = high - third;

        (*comparisons)++;
        if (a[mid1] == x)
            return mid1;

        (*comparisons)++;
        if (a[mid2] == x)
            return mid2;

        if (x < a[mid1]) {
            high = mid1 - 1;
        }
        else if (x > a[mid2]) {
            low = mid2 + 1;
        }
        else {
            low = mid1 + 1;
            high = mid2 - 1;
        }
    }

    return -1;
}

int main() {
    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));

    printf("Enter sorted array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to search: ");
    scanf("%d", &x);

    int binaryComparisons = 0;
    int ternaryComparisons = 0;

    int b = binarySearch(a, n, x, &binaryComparisons);
    int t = ternarySearch(a, n, x, &ternaryComparisons);

    printf("\nBinary Search:\n");
    printf("Position = %d\n", b);
    printf("Comparisons = %d\n", binaryComparisons);

    printf("\nTernary Search:\n");
    printf("Position = %d\n", t);
    printf("Comparisons = %d\n", ternaryComparisons);

    if (binaryComparisons < ternaryComparisons)
        printf("\nBinary Search performed fewer comparisons.\n");
    else
        printf("\nFor this particular input, ternary search used fewer comparisons.\n");

    free(a);

    return 0;
}