//q.1.Find the Median Without Sorting

#include <stdio.h>
#include <stdlib.h>

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;
    int j, temp;

    for (j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;

            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

int quickSelect(int a[], int low, int high, int k)
{
    if (low == high)
        return a[low];

    int p = partition(a, low, high);

    if (k == p)
        return a[p];

    if (k < p)
        return quickSelect(a, low, p - 1, k);

    return quickSelect(a, p + 1, high, k);
}

int main()
{
    int n, i;
    double median;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    if (n % 2 != 0)
    {
       
        median = quickSelect(a, 0, n - 1, n / 2);
    }
    else
    {
        int x = quickSelect(a, 0, n - 1, n / 2 - 1);
        int y = quickSelect(a, 0, n - 1, n / 2);

        median = (x + y) / 2.0;
    }

    printf("Median = %.2f\n", median);

    free(a);

    return 0;
}
