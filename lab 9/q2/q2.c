//q.2.Huffman Coding and Canonical Huffman Codes


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 26
#define NODES (2 * MAX)

typedef struct {
    char symbol;
    int frequency;
    int left, right;
    int used;
} Node;

typedef struct {
    char symbol;
    int length;
} Code;

Node tree[NODES];
Code codes[MAX];
int nodeCount = 0, codeCount = 0;

int newNode(char symbol, int frequency, int left, int right) {
    int id = nodeCount++;
    tree[id].symbol = symbol;
    tree[id].frequency = frequency;
    tree[id].left = left;
    tree[id].right = right;
    tree[id].used = 0;
    return id;
}

void getLengths(int id, int depth) {
    if (tree[id].left == -1 && tree[id].right == -1) {
        codes[codeCount].symbol = tree[id].symbol;
        codes[codeCount].length = depth ? depth : 1;
        codeCount++;
        return;
    }

    getLengths(tree[id].left, depth + 1);
    getLengths(tree[id].right, depth + 1);
}

int main(void) {
    int n, i, a, b, root;
    int frequency[MAX];
    char symbol[MAX];

    printf("Enter number of symbols: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of symbols.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter uppercase symbol and frequency: ");
        scanf(" %c %d", &symbol[i], &frequency[i]);
        newNode(symbol[i], frequency[i], -1, -1);
    }

    while (1) {
        a = b = -1;

        for (i = 0; i < nodeCount; i++) {
            if (tree[i].used) continue;

            if (a == -1 || tree[i].frequency < tree[a].frequency) {
                b = a;
                a = i;
            } else if (b == -1 || tree[i].frequency < tree[b].frequency) {
                b = i;
            }
        }

        if (b == -1) {
            root = a;
            break;
        }

        tree[a].used = tree[b].used = 1;

        newNode('*', tree[a].frequency + tree[b].frequency, a, b);
    }

    getLengths(root, 0);

    for (i = 0; i < codeCount; i++) {
        int j;
        for (j = i + 1; j < codeCount; j++) {
            if (codes[j].length < codes[i].length ||
                (codes[j].length == codes[i].length &&
                 codes[j].symbol < codes[i].symbol)) {
                Code temp = codes[i];
                codes[i] = codes[j];
                codes[j] = temp;
            }
        }
    }

    unsigned long long current = 0;
    int previousLength = codes[0].length;

    printf("\nCanonical Huffman Codebook:\n");

    for (i = 0; i < codeCount; i++) {
        if (i > 0) {
            current = (current + 1) << (codes[i].length - previousLength);
        }

        printf("%c : ", codes[i].symbol);

        for (int bit = codes[i].length - 1; bit >= 0; bit--)
            printf("%d", (int)((current >> bit) & 1ULL));

        printf("\n");
        previousLength = codes[i].length;
    }

    return 0;
}