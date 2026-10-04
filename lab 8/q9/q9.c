//q.9.Collatz Conjecture

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <limits.h>

int nextCollatz(uint64_t n, uint64_t *next) {
    if (n % 2 == 0) {
        *next = n / 2;
        return 1;
    }

    if (n > (UINT64_MAX - 1) / 3)
        return 0;

    *next = 3 * n + 1;
    return 1;
}

void analyze(uint64_t n) {
    uint64_t current = n;
    uint64_t steps = 0;
    uint64_t maximum = n;

    printf("Trajectory: ");

    while (1) {
        printf("%" PRIu64, current);

        if (current == 1)
            break;

        printf(" -> ");

        uint64_t next;

        if (!nextCollatz(current, &next)) {
            printf("\nOverflow detected!\n");
            return;
        }

        current = next;
        if (current > maximum)
            maximum = current;

        steps++;
    }

    printf("\nStarting value = %" PRIu64 "\n", n);
    printf("Steps = %" PRIu64 "\n", steps);
    printf("Maximum value = %" PRIu64 "\n", maximum);
}

void analyzeInterval(uint64_t a, uint64_t b) {
    if (a == 0 || a > b) {
        printf("Invalid interval\n");
        return;
    }

    for (uint64_t i = a;; i++) {
        printf("\nStarting number: %" PRIu64 "\n", i);
        analyze(i);

        if (i == b)
            break;
    }
}

int main() {
    uint64_t n, a, b;

    printf("Enter starting number: ");
    scanf("%" SCNu64, &n);

    if (n == 0) {
        printf("Enter a positive integer.\n");
        return 1;
    }

    analyze(n);

    printf("\nEnter interval [a, b]: ");
    scanf("%" SCNu64 " %" SCNu64, &a, &b);

    analyzeInterval(a, b);

    return 0;
}