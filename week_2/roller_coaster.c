// part5_roller_coaster
//
// This program was written by YOUR-NAME, ZID
// on [DATE]
//
// This program:
// 1. Scans in the users height.
//
// 2. If the height is 0 or less, 
//    it should print an error message
//
// 3. If the height is below the minimum height, 
//    it should print a message telling the user they are not tall enough to ride
// 
// 4. If the height is above the minimum but below the ride alone threshold,
//    it should print a message telling the user they can ride with an adult
//
// 5. If the height is or is above the ride alone threshold, 
//    it should print a message telling the user they can ride.

#include <stdio.h>

#define MIN_HEIGHT_RIDE 100.0
#define MIN_HEIGHT_ALONE 160.0

int main(void) {
    double height;
    printf("What is you height? ");
    scanf("%lf", &height);
    
    if (height <= 0) {
        printf("ERROR: Invalid Height\n");
    } else if (height <= MIN_HEIGHT_RIDE) {
        printf("Not tall enough to ride\n");
    } else if (height < MIN_HEIGHT_ALONE) {
        printf("Must ride with an adult\n");
    } else {
        printf("You are tall enough to ride alone!\n");
    }

    return 0;
}