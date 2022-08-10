#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIMENSIONS 3

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