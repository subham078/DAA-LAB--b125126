
#include <stdio.h>

#define MAX 1000

int heap[MAX];
int size = 0;

void push(int x) {
    int i = size++;
    while (i > 0 && heap[(i - 1) / 2] > x) {
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
        if (child + 1 < size && heap[child + 1] < heap[child])
            child++;
        if (last <= heap[child]) break;
        heap[i] = heap[child];
        i = child;
    }

    if (size > 0) heap[i] = last;
    return result;
}

int main(void) {
    int n, i, a, b, combined;
    long long total = 0;

    printf("Enter number of sticks: ");
    scanf("%d", &n);

    if (n < 1 || n >= MAX) {
        printf("Invalid number of sticks.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        int length;
        scanf("%d", &length);
        push(length);
    }

    while (size > 1) {
        a = pop();
        b = pop();
        combined = a + b;
        total += combined;
        push(combined);
    }

    printf("Minimum total cost = %lld\n", total);
    return 0;
}