#include <stdio.h>

void selectionSort(int a[], int n) {

    for (int i = 0; i < n - 1; i++) {

        int minIndex = i;

        for (int j = i + 1; j < n; j++) {

            if (a[j] < a[minIndex])
                minIndex = j;
        }

        // Exchange A[i] and A[minIndex]
        int temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }
}

void printArray(int a[], int n) {

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int main() {

    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\nBefore sorting:\n");
    printArray(a, n);

    selectionSort(a, n);

    printf("\nAfter sorting:\n");
    printArray(a, n);

    return 0;
}