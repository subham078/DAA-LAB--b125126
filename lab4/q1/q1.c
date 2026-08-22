//q.1. APPLICATION OF SORTING-I
#include <stdio.h>
#include <string.h>

struct Item {
    int number;
    char color[10];
};

int main() {
    int n;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item red[n], blue[n], yellow[n];
    int r = 0, b = 0, y = 0;

    printf("Enter number and color (red/blue/yellow):\n");

    for (int i = 0; i < n; i++) {
        int num;
        char color[10];

        scanf("%d %s", &num, color);

        if (strcmp(color, "red") == 0) {
            red[r].number = num;
            strcpy(red[r].color, color);
            r++;
        }
        else if (strcmp(color, "blue") == 0) {
            blue[b].number = num;
            strcpy(blue[b].color, color);
            b++;
        }
        else if (strcmp(color, "yellow") == 0) {
            yellow[y].number = num;
            strcpy(yellow[y].color, color);
            y++;
        }
    }

    printf("\nSorted by color:\n");

    for (int i = 0; i < r; i++)
        printf("(%d, %s)\n", red[i].number, red[i].color);

    for (int i = 0; i < b; i++)
        printf("(%d, %s)\n", blue[i].number, blue[i].color);

    for (int i = 0; i < y; i++)
        printf("(%d, %s)\n", yellow[i].number, yellow[i].color);

    return 0;
}
