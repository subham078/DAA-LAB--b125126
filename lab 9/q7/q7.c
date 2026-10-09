//q.7.Minimise Deviation in an Array


#include <stdio.h>

#define MAX 1000

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
    int result = heap[0], last = heap[--size];
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
    int n, i, x, minimum = 1000000000;
    int deviation, answer;

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n < 1 || n >= MAX) {
        printf("Invalid array size.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        scanf("%d", &x);

        if (x <= 0 || x > 1000000000) {
            printf("Values must be positive and within range.\n");
            return 1;
        }

        if (x % 2 == 1)
            x *= 2;

        if (x < minimum)
            minimum = x;

        push(x);
    }

    answer = heap[0] - minimum;

    while (heap[0] % 2 == 0) {
        x = pop();
        x /= 2;

        if (x < minimum)
            minimum = x;

        push(x);

        deviation = heap[0] - minimum;

        if (deviation < answer)
            answer = deviation;
    }

    printf("Minimum deviation = %d\n", answer);
    return 0;
}