//q.3.Minimum Number of Refuelling Stops

#include <stdio.h>
#define MAX 1000
typedef struct {
    int distance;
    int fuel;
} Station;
int heap[MAX];
int size = 0;
void push(int x) {
    int i = size++;
    while (i > 0 && heap[(i - 1) / 2] < x) {
        heap[i] = heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap[i] = x;
}
int pop(void) {
    int result = heap[0];
    int last = heap[--size];
    int i = 0, child;
    while (2 * i + 1 < size) {
        child = 2 * i + 1;

        if (child + 1 < size && heap[child + 1] > heap[child])
            child++;

        if (last >= heap[child]) break;

        heap[i] = heap[child];
        i = child;
    }

    if (size > 0) heap[i] = last;
    return result;
}
int main(void) {
    int n, D, F, i, stops = 0, reachable = 0;
    Station s[MAX];

    printf("Enter target distance and initial fuel: ");
    scanf("%d %d", &D, &F);

    printf("Enter number of stations: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter station distance and fuel: ");
        scanf("%d %d", &s[i].distance, &s[i].fuel);
    }

    for (i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[j].distance < s[i].distance) {
                Station temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    for (i = 0; i <= n; i++) {
        int next = (i == n) ? D : s[i].distance;

        while (reachable < next) {
            if (size == 0) {
                printf("Target is unreachable.\n");
                return 0;
            }

            reachable += pop();
            stops++;
        }

        if (i < n) push(s[i].fuel);
    }

    printf("Minimum refuelling stops = %d\n", stops);
    return 0;
}