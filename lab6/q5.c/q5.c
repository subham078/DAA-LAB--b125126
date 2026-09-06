//q.5. 1D Array Operations and Their Complexities

#include <stdio.h>
#include <math.h>

/* (i) Find Maximum */
int findMaximum(int a[], int n)
{
    int max = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }

    return max;
}

/* (ii) Find First and Second Largest */
void findLargestTwo(int a[], int n)
{
    int largest, second;

    if (a[0] > a[1])
    {
        largest = a[0];
        second = a[1];
    }
    else
    {
        largest = a[1];
        second = a[0];
    }

    for (int i = 2; i < n; i++)
    {
        if (a[i] > largest)
        {
            second = largest;
            largest = a[i];
        }
        else if (a[i] > second)
        {
            second = a[i];
        }
    }

    printf("Largest = %d\n", largest);
    printf("Second Largest = %d\n", second);
}

/* (iii) Find Mean */
double findMean(int a[], int n)
{
    double sum = 0;

    for (int i = 0; i < n; i++)
        sum += a[i];

    return sum / n;
}

/* Sorting used for Median */
void sortArray(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }

        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

/* (iv) Find Median */
double findMedian(int a[], int n)
{
    sortArray(a, n);

    if (n % 2 == 1)
        return a[n / 2];

    return (a[n / 2 - 1] + a[n / 2]) / 2.0;
}

/* (v) Find Standard Deviation */
double findStandardDeviation(int a[], int n)
{
    double mean = findMean(a, n);
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        double difference = a[i] - mean;
        sum += difference * difference;
    }

    return sqrt(sum / n);
}

/* (vi) Find Mode */
int findMode(int a[], int n)
{
    int mode = a[0];
    int maxFrequency = 0;

    for (int i = 0; i < n; i++)
    {
        int frequency = 0;

        for (int j = 0; j < n; j++)
        {
            if (a[i] == a[j])
                frequency++;
        }

        if (frequency > maxFrequency)
        {
            maxFrequency = frequency;
            mode = a[i];
        }
    }

    return mode;
}

/* (vii) Remove All Duplicates */
void removeDuplicates(int a[], int *n)
{
    for (int i = 0; i < *n; i++)
    {
        for (int j = i + 1; j < *n;)
        {
            if (a[i] == a[j])
            {
                for (int k = j; k < *n - 1; k++)
                    a[k] = a[k + 1];

                (*n)--;
            }
            else
            {
                j++;
            }
        }
    }
}

/* (viii) Reverse Array */
void reverseArray(int a[], int n)
{
    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;

        i++;
        j--;
    }
}

/* (ix) Partition with respect to Pivot */
void partitionArray(int a[], int n, int pivot)
{
    int i = 0;

    for (int j = 0; j < n; j++)
    {
        if (a[j] < pivot)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;

            i++;
        }
    }
}

/* Display Array */
void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int main()
{
    int n, choice, pivot;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter array elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    do
    {
        printf("\n========== ARRAY OPERATIONS ==========\n");
        printf("1. Find Maximum\n");
        printf("2. Find First and Second Largest\n");
        printf("3. Find Mean\n");
        printf("4. Find Median\n");
        printf("5. Find Standard Deviation\n");
        printf("6. Find Mode\n");
        printf("7. Remove Duplicates\n");
        printf("8. Reverse Array\n");
        printf("9. Partition Array\n");
        printf("10. Display Array\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Maximum = %d\n", findMaximum(a, n));
            break;

        case 2:
            findLargestTwo(a, n);
            break;

        case 3:
            printf("Mean = %.2lf\n", findMean(a, n));
            break;

        case 4:
            printf("Median = %.2lf\n", findMedian(a, n));
            break;

        case 5:
            printf("Standard Deviation = %.2lf\n",
                   findStandardDeviation(a, n));
            break;

        case 6:
            printf("Mode = %d\n", findMode(a, n));
            break;

        case 7:
            removeDuplicates(a, &n);
            printf("Array after removing duplicates:\n");
            display(a, n);
            break;

        case 8:
            reverseArray(a, n);
            printf("Reversed array:\n");
            display(a, n);
            break;

        case 9:
            printf("Enter pivot: ");
            scanf("%d", &pivot);

            partitionArray(a, n, pivot);

            printf("Array after partition:\n");
            display(a, n);
            break;

        case 10:
            display(a, n);
            break;

        case 0:
            printf("Program terminated.\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}