// part1_while_loops.c
//
// Written by YOUR-NAME (zID), 
// on TODAYS-DATE
//
// This program is a simple demonstration of a count loop in c

#include <stdio.h>

int main(void) {
    int x;
    printf("Start of loop!\n");

    scanf("%d", &x);
    while (x < 10) {
        printf("%d\n", x);
        x++; // Shorthand for x = x + 1;
    }
    printf("END OF LOOP!");

    return 0;
}
