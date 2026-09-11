/* Q5. Hitting a Moving Target */

#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define STATES (1 << MAX)

typedef struct {
    int state;
    int parent;
    int shot;
} Node;

int main() {
    int n;
    scanf("%d", &n);

    if (n > MAX) {
        printf("n is too large\n");
        return 0;
    }

    int total = 1 << n;

    int *visited = calloc(total, sizeof(int));
    Node *nodes = malloc(total * sizeof(Node));
    int *queue = malloc(total * sizeof(int));

    int start = (1 << n) - 1;

    int front = 0, rear = 0;
    queue[rear++] = start;

    visited[start] = 1;

    int goal = -1;

    while (front < rear) {
        int state = queue[front];
        int current = front++;

        if (state == 0) {
            goal = current;
            break;
        }

        for (int shot = 0; shot < n; shot++) {
            int afterShot = state & ~(1 << shot);

            if (afterShot == 0) {
                nodes[current].shot = shot;
                nodes[current].parent = -1;
                goal = current;
                break;
            }

            int nextState = 0;

            for (int i = 0; i < n; i++) {
                if (afterShot & (1 << i)) {
                    if (i > 0)
                        nextState |= (1 << (i - 1));

                    if (i < n - 1)
                        nextState |= (1 << (i + 1));
                }
            }

            if (!visited[nextState]) {
                visited[nextState] = 1;

                nodes[rear].state = nextState;
                nodes[rear].parent = current;
                nodes[rear].shot = shot;

                queue[rear++] = nextState;
            }
        }

        if (goal != -1)
            break;
    }

    if (goal == -1) {
        printf("No guaranteed strategy exists.\n");
    } else {
        printf("A guaranteed shooting sequence exists.\n");
    }

    free(visited);
    free(nodes);
    free(queue);

    return 0;
}