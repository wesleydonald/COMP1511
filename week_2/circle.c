// part1_variables
//
// This program was written by YOUR-NAME (ZID),
// on [DATE]
//
// This program calculates the area of a circle

#include <stdio.h>

#define PI 3.14159

int main(void) {
    // 1. Declare the variables
    int radius;

    // 2. Initialise the variables
    printf("Scan in radius: ");
    scanf("%d", &radius);

    // 3. Calculate the area of a circle
    double area = PI * radius * radius;

    // 4. Print the result

    // %lf is a format specifier which says 
    // print two decimal places
    printf("The area is: %.2lf\n", area);  
    return 0;
}