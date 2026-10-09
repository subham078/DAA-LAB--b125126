//q.8.Minimum Number of Meeting Rooms


#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int compare(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

int main(void) {
    int n, i;
    int start[MAX], end[MAX];
    int rooms = 0, maximum = 0;
    int s = 0, e = 0;

    printf("Enter number of meetings: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of meetings.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter start and end time: ");
        scanf("%d %d", &start[i], &end[i]);

        if (start[i] >= end[i]) {
            printf("Invalid interval.\n");
            return 1;
        }
    }

    qsort(start, n, sizeof(int), compare);
    qsort(end, n, sizeof(int), compare);

    while (s < n) {
        if (e < n && start[s] >= end[e]) {
            rooms--;
            e++;
        } else {
            rooms++;
            if (rooms > maximum)
                maximum = rooms;
            s++;
        }
    }

    printf("Minimum meeting rooms = %d\n", maximum);
    return 0;
}