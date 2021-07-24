#include "typedef.h"

#define GRN "\e[0;92m"
#define YEL "\e[0;93m"

#define NC "\e[0m"

double calc_distance(int dimensions, double a[dimensions], double b[dimensions]) {
    double square_distance = 0;
    for (int i = 0; i < dimensions; i++) {
        square_distance += pow(a[i] - b[i], 2);
    }
    return sqrt(square_distance);
}

int main() {
    printf("\n=== Initializing Structures ===\n\n");

    /* Let's calculate the distance between two guys */

    /* Implicit initialization */
    Person elon = {
        "Elon Musk",
        true,
        3,
        {1, 2, 3}};

    /* Explicit initialization */
    Person bill = {
        .name = "Bill Gates",
        .pos = {3, 2, 1},
        .dimensions = 3,
        .active = true,
    };

    Motorcycle moto = {
        .model = "honda",
        .speed = 100,
        .owner = {
            .name = "Andrea",
            .dimensions = 3,
            .active = true,
            .pos = {0, 0, 0}},
    };

    /* Copy a whole structure with = */
    Person anotherGuy = {.name = "someone", .active = false};
    anotherGuy = bill;

    printf("anotherGuy.name = %s\n", anotherGuy.name);

    if (!elon.active || !bill.active) {
        printf("%s isn't active now!\n", !elon.active ? elon.name : bill.name);
        return EXIT_FAILURE;
    }

    if (elon.dimensions != bill.dimensions) {
        printf("%s and %s are in different dimensions!\n", elon.name, bill.name);
        return EXIT_FAILURE;
    }

    printf("The distance between %s and %s is: %.1f\n",
           elon.name, bill.name, calc_distance(elon.dimensions, elon.pos, bill.pos));

    printf(GRN "\nAnd a %s motorcycle is running at %.1f km/h and is driven by %s\n\n" NC, moto.model, moto.speed, moto.owner.name);

    // Set new value...
    // moto = (Motorcycle){.model = "Ducati", .speed = 200, .owner.name = "A"};
    moto = (Motorcycle){
        .model = "Ducati",
        .speed = 200,
    };

    printf(YEL "And a %s motorcycle is running at %.1f km/h and is driven by %s\n" NC, moto.model, moto.speed, moto.owner.name);

    return EXIT_SUCCESS;
}
