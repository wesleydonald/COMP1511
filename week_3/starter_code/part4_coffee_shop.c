// coffee_shop.c
//
// Written by YOUR-NAME (zID)
// on TODAYS-DATE 
//
// This program is a simple coffee shop used to demonstrate the use of 
// structs and enums in C. This program takes user input for a coffee order
// and outputs the cost of the order.

#include <stdio.h>

#define LARGE 'L'
#define REGULAR 'R'
#define ADDED_COST 0.5
#define BASE_COST 4.5

// Define an enum `coffee_type` that stores the different types of coffees 
// the shop sells. These are: LATTE, CAPPUCCINO, ESPRESSO, AMERICANO & MATCHA.
enum coffee_type {
    LATTE,
    CAPPUCCINO,
    ESPRESSO,
    AMERICANO,
    MATCHA
};

// Define a struct `coffee` that stores 
// 1. the coffee type (an enum)
// 2. the number of sugars 
// 3. the size of a coffee 
struct coffee {
    enum coffee_type type;
    int num_sugars;
    char size;
};

int main(void) {
    // Declare a variable for the struct
    struct coffee my_coffee;
    // my_coffee.type = LATTE;
    // my_coffee.num_sugars = 5;
    // my_coffee.size = LARGE; // #defined to 'L'

    printf("Enter coffee type (0: LATTE, 1: CAPPUCCINO, 2: ESPRESSO, \
            3: AMERICANO, 4: MATCHA): ");
    int type;
    scanf("%d", &type);
    my_coffee.type = type;
    
    printf("Enter number of sugars: ");
    scanf("%d", &my_coffee.num_sugars);

    printf("Enter size (L for Large, R for Regular): ");
    scanf(" %c", &my_coffee.size);

    // Calculate cost of order
    double total_cost = BASE_COST;

    if (my_coffee.size == LARGE) {
        total_cost += ADDED_COST;
    }

    if (my_coffee.type == LATTE || 
            my_coffee.type == CAPPUCCINO|| 
            my_coffee.type == MATCHA) {
            total_cost += ADDED_COST;
    }
    
    total_cost += ADDED_COST * my_coffee.num_sugars;
    printf("Total cost: %.2lf\n", total_cost);
    return 0;
}
