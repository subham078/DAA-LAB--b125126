//q.6.Reorganise String with K-Distance Apart


#include <stdio.h>
#include <string.h>

#define MAX 10000
#define ALPHABET 256

typedef struct {
    int ch, count;
} Item;

Item heap[ALPHABET];
int size = 0;

void push(Item x) {
    int i = size++;
    while (i > 0 && heap[(i - 1) / 2].count < x.count) {
        heap[i] = heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap[i] = x;
}

Item pop(void) {
    Item result = heap[0], last = heap[--size];
    int i = 0, child;

    while (2 * i + 1 < size) {
        child = 2 * i + 1;
        if (child + 1 < size &&
            heap[child + 1].count > heap[child].count)
            child++;
        if (last.count >= heap[child].count) break;
        heap[i] = heap[child];
        i = child;
    }

    if (size > 0) heap[i] = last;
    return result;
}

int main(void) {
    char s[MAX], result[MAX];
    int freq[ALPHABET] = {0};
    Item waiting[ALPHABET];
    int release[ALPHABET];
    int front = 0, back = 0, i, K, length;

    printf("Enter string: ");
    scanf("%9999s", s);
    printf("Enter K: ");
    scanf("%d", &K);

    if (K < 0) {
        printf("Invalid K.\n");
        return 1;
    }

    length = (int)strlen(s);

    for (i = 0; i < length; i++)
        freq[(unsigned char)s[i]]++;

    if (K <= 1) {
        printf("Result: %s\n", s);
        return 0;
    }

    for (i = 0; i < ALPHABET; i++) {
        if (freq[i] > 0) {
            Item x = {i, freq[i]};
            push(x);
        }
    }

    for (i = 0; i < length; i++) {
        while (front < back && release[front] <= i) {
            if (waiting[front].count > 0)
                push(waiting[front]);
            front++;
        }

        if (size == 0) {
            printf("Result: \n");
            return 0;
        }

        Item x = pop();
        result[i] = (char)x.ch;
        x.count--;

        waiting[back] = x;
        release[back] = i + K;
        back++;
    }

    result[length] = '\0';
    printf("Result: %s\n", result);
    return 0;
}