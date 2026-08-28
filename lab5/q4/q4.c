//q.4. Heap Sort on Randomly Generated Elements Stored in a File

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Swap two elements */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Heapify */
void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    /* Check left child */
    if (left < n && a[left] > a[largest])
        largest = left;

    /* Check right child */
    if (right < n && a[right] > a[largest])
        largest = right;

    /* If largest is not root */
    if (largest != i)
    {
        swap(&a[i], &a[largest]);

        heapify(a, n, largest);
    }
}

/* Heap Sort */
void heapSort(int a[], int n)
{
    int i;

    /* Build Max Heap */
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    /* Extract elements from heap */
    for (i = n - 1; i > 0; i--)
    {
        swap(&a[0], &a[i]);

        heapify(a, i, 0);
    }
}

int main()
{
    FILE *fp;
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));

    if (a == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    /* Initialize random number generator */
    srand((unsigned int)time(NULL));

    /* Generate and store random numbers */
    fp = fopen("heap_numbers.txt", "w");

    if (fp == NULL)
    {
        printf("Unable to open file.\n");
        free(a);
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 1000;
        fprintf(fp, "%d ", a[i]);
    }

    fclose(fp);

    /* Reset array */
    for (i = 0; i < n; i++)
        a[i] = 0;

    /* Read numbers from file */
    fp = fopen("heap_numbers.txt", "r");

    if (fp == NULL)
    {
        printf("Unable to open file.\n");
        free(a);
        return 1;
    }

    for (i = 0; i < n; i++)
        fscanf(fp, "%d", &a[i]);

    fclose(fp);

    printf("\nOriginal elements:\n");

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    /* Heap Sort */
    heapSort(a, n);

    printf("\n\nSorted elements using Heap Sort:\n");

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");

    free(a);

    return 0;
}
