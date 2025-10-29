// Sum of Command Line Arguments
// This program takes multiple integers as command-line 
// arguments and prints their sum.
// Written by Wesley Donald

#include <stdlib.h> // For atoi()
#include <stdio.h>

int main(int argc, char *argv[]) {
    int sum = 0;

    for (int i = 1; i < argc; i++) {
        sum += atoi(argv[i]);
    }

    printf("Sum: %d\n", sum);

    return 0;
}
