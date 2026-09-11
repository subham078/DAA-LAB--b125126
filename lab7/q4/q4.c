/* Q4. Security Switches */

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int s[n];

    for (int i = 0; i < n; i++)
        s[i] = 1;

    int moves = 0;

    while (1) {
        int done = 1;

        for (int i = 0; i < n; i++) {
            if (s[i] == 1) {
                done = 0;
                break;
            }
        }

        if (done)
            break;

        for (int i = 0; i < n; i++) {
            int allowed = 0;

            if (i == n - 1) {
                allowed = 1;
            } else {
                if (s[i + 1] == 1) {
                    allowed = 1;

                    for (int j = i + 2; j < n; j++) {
                        if (s[j] == 1) {
                            allowed = 0;
                            break;
                        }
                    }
                }
            }

            if (allowed && s[i] == 1) {
                s[i] = 0;
                moves++;

                printf("Toggle switch %d\n", i + 1);
                break;
            }
        }
    }

    printf("Minimum moves = %d\n", moves);

    return 0;
}