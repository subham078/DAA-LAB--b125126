#include <stdio.h>

int findDefective(int a[], int left, int right, int good) {

    if (left == right) {
        if (a[left] < a[good])
            return left;

        return -1;
    }

    int n = right - left + 1;

    if (n == 2) {
        if (a[left] < a[right])
            return left;

        if (a[right] < a[left])
            return right;

        return -1;
    }

    int mid = (left + right) / 2;

    int sumLeft = 0;
    int sumRight = 0;

    for (int i = left; i <= mid; i++)
        sumLeft += a[i];

    for (int i = mid + 1; i <= right; i++)
        sumRight += a[i];

    if (sumLeft < sumRight)
        return findDefective(a, left, mid, good);

    else if (sumRight < sumLeft)
        return findDefective(a, mid + 1, right, good);

    return -1;
}

int main() {

    int n;

    printf("Enter number of coins: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter weights of coins:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);


    int defective = -1;

    int min = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
            defective = i;
        }
    }

    if (defective == -1)
        printf("No defective coin found.\n");
    else
        printf("Defective coin = %d\n", defective + 1);

    return 0;
}