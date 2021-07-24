#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIMENSIONS 3

/** 
 * *! 1. Struct Declaration
 * */
// struct PersonStruct {
//     char *name;
//     bool active;
//     int dimensions;
//     double pos[MAX_DIMENSIONS];

// in general we cannot use incomplete arrays, but...
// see Flexible Array Member
// };
/** 
 * *! 2. Aliasing the type with typedef (anonymous struct)
 * */
// typedef struct
// {
//     char *name;
//     bool active;
//     int dimensions;
//     double pos[MAX_DIMENSIONS];
// } PersonAnonymous;

/** 
 * *! 3. Aliasing the type with typedef (good practice)
 * */
typedef struct PersonStruct {
    char *name;
    bool active;
    int dimensions;
    double pos[MAX_DIMENSIONS];
    struct Person *friend;
} Person;

typedef struct Motorcycle {
    char *model;
    double speed;
    Person owner;
} Motorcycle;

double calc_distance(int dimensions, double a[dimensions], double b[dimensions]) {
    double square_distance = 0;
    for (int i = 0; i < dimensions; i++) {
        square_distance += pow(a[i] - b[i], 2);
    }
    return sqrt(square_distance);
}

int main() {
    printf("\n=== Defining And Accessing Structures ===\n\n");

    /* Let's calculate the distance between two guys */

    Person elon, bill;
    Motorcycle moto;

    moto.model = "honda";
    moto.speed = 300;
    moto.owner.name = "Andrea";

    elon.name = "Elon Musk";
    elon.active = true;
    elon.dimensions = 3;
    elon.pos[0] = 1;
    elon.pos[1] = 2;
    elon.pos[2] = 3;

    bill.name = "Bill Gates";
    bill.active = true;
    bill.dimensions = 3;
    bill.pos[0] = 3;
    bill.pos[1] = 2;
    bill.pos[2] = 1;

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

    return EXIT_SUCCESS;
}
