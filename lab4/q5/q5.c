//q.5. APPLICATION OF SORTING-V

#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int start;
    int end;
};

int compare(const void *a, const void *b) {
    struct Interval *i1 = (struct Interval *)a;
    struct Interval *i2 = (struct Interval *)b;

    return i1->start - i2->start;
}

int main() {
    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    struct Interval arr[n];

    printf("Enter intervals:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    qsort(arr, n, sizeof(struct Interval), compare);

    struct Interval merged[n];
    int count = 0;

    merged[count++] = arr[0];

    for (int i = 1; i < n; i++) {

        if (arr[i].start <= merged[count - 1].end) {

            if (arr[i].end > merged[count - 1].end)
                merged[count - 1].end = arr[i].end;

        }
        else {
            merged[count++] = arr[i];
        }
    }

    printf("\nMerged intervals:\n");

    for (int i = 0; i < count; i++) {
        printf("(%d, %d) ",
               merged[i].start,
               merged[i].end);
    }

    printf("\n");

    return 0;
}