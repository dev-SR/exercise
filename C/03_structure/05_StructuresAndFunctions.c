#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"

#define MAX_DIMENSIONS 3

typedef struct Person {
    char *name;
    bool active;
    int dimensions;
    double pos[MAX_DIMENSIONS];
    struct Person *friend;
} Person;

Person create_bill() {
    return (Person){
        .name = "Bill Gates",
        .pos = {1, 2, 3},
        .dimensions = 3,
        .active = true,
    };
}

Person *alloc_elon() {
    Person *elon = malloc(sizeof(Person));

    if (!elon) {
        return NULL;
    }

    /* Settings... */
    elon->name = "Elon Musk";
    elon->active = true;
    elon->dimensions = 3;
    double pos[] = {4, 5, 6};
    memcpy(elon->pos, pos, sizeof(pos));
    elon->friend = NULL;

    return elon;
}

void deactivate(Person g) {
    g.active = false;
}

void deactivate_ptr(Person *pg) {
    pg->active = false;
}

int main() {
    printf("\n=== Structures And Functions ===\n\n");

    Person bill = create_bill();
    bill.friend = alloc_elon();

    deactivate(bill);
    deactivate_ptr(&bill);

    return EXIT_SUCCESS;
}