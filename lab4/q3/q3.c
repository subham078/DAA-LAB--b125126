//q.3. APPLICATION OF SORTING-III

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return 1;

        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return 0;
}

int findKSum(int arr[], int n, int k, int index,
             int count, long long sum, int target) {

    if (count == k - 1) {
        long long needed = target - sum;

        return binarySearch(arr, n, (int)needed);
    }

    for (int i = index; i < n; i++) {
        if (findKSum(arr, n, k, i + 1,
                     count + 1, sum + arr[i], target))
            return 1;
    }

    return 0;
}

int main() {
    int n, k, T;

    printf("Enter n: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter k: ");
    scanf("%d", &k);

    printf("Enter T: ");
    scanf("%d", &T);

    if (k < 2 || k > n) {
        printf("Invalid value of k.\n");
        return 0;
    }

    qsort(arr, n, sizeof(int), compare);

    if (findKSum(arr, n, k, 0, 0, 0, T))
        printf("Yes, %d elements add up to %d.\n", k, T);
    else
        printf("No such combination exists.\n");

    return 0;
}