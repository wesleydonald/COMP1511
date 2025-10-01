// This program demostrates scanning in a while loop
#include <stdio.h>

int main(void) { 
    // display all even numbers entered

    printf("Enter character: ");
    char c;

    while (scanf("%d", &c) == 1 && c != 'q') {
        printf("%c\n", c);
    }

    // typing ctrl-d means "End of file"
    return 0;
}

