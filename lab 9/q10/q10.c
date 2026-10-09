//q.10.Greedy Superstring Conjecture


#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 100
#define MAX_LEN 10000

int overlap(const char *a, const char *b) {
    int la = (int)strlen(a);
    int lb = (int)strlen(b);
    int limit = la < lb ? la : lb;

    for (int k = limit; k > 0; k--) {
        if (strncmp(a + la - k, b, k) == 0)
            return k;
    }

    return 0;
}

int main(void) {
    int n, i, j;

    static char s[MAX_STRINGS][MAX_LEN];

    printf("Enter number of strings: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_STRINGS) {
        printf("Invalid number of strings.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        scanf("%9999s", s[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (strstr(s[i], s[j]) != NULL) {
                s[j][0] = '\0';
            } else if (strstr(s[j], s[i]) != NULL) {
                s[i][0] = '\0';
            }
        }
    }

    while (1) {
        int best = 0, bi = -1, bj = -1;

        for (i = 0; i < n; i++) {
            if (s[i][0] == '\0') continue;

            for (j = 0; j < n; j++) {
                if (i == j || s[j][0] == '\0') continue;

                int ov = overlap(s[i], s[j]);

                if (ov > best) {
                    best = ov;
                    bi = i;
                    bj = j;
                }
            }
        }

        if (bi == -1) break;

        strcat(s[bi], s[bj] + best);
        s[bj][0] = '\0';
    }

    for (i = 0; i < n; i++) {
        if (s[i][0] != '\0') {
            printf("Greedy superstring: %s\n", s[i]);
            break;
        }
    }

    return 0;
}