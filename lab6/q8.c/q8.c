//q.8.SORTING VIA REVERSAL PROCEDURE

#include <stdio.h>

/* Reverse elements from l to r */
void reverse(int p[], int l, int r)
{
    while (l < r)
    {
        int temp = p[l];
        p[l] = p[r];
        p[r] = temp;

        l++;
        r--;
    }
}

/* Sort permutation using reversals */
void sortByReversal(int p[], int n)
{
    int reversalCount = 0;

    for (int i = 0; i < n; i++)
    {
        /*
           Find the position of i+1
        */
        int position = i;

        for (int j = i; j < n; j++)
        {
            if (p[j] == i + 1)
            {
                position = j;
                break;
            }
        }

        /*
           Put i+1 at position i
        */
        if (position != i)
        {
            reverse(p, i, position);
            reversalCount++;
        }
    }

    printf("\nNumber of reversals = %d\n", reversalCount);
}

int main()
{
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    int p[n];

    printf("Enter permutation:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);

    sortByReversal(p, n);

    printf("\nSorted permutation:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", p[i]);

    printf("\n");

    return 0;
}