// This program is a simple deonstration of a 2D while loop 

#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5

int main(void) {
    printf("Start of outer loop!\n");
    int row = 0;
    int col = 0;

    while (row < MAX_ROW) {
        printf("Start of inner loop\n");

        col = 0;
        while (col < MAX_COL) {
            printf("%d\n", col);
            col++;
        }
        printf("End of inner loop\n");
        row++;
    }

    return 0;
}
