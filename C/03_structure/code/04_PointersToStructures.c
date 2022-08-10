#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
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
void free_chain(struct Person *p);
int main() {
    printf("\n=== Pointers To Structures ===\n\n");

    Person bill = {
        .name = "Bill Gates",
        .pos = {3, 2, 1},
        .dimensions = 3,
        .active = true,
    };

    Person *firstGuy = &bill;

    /* 1) Accessing the struct directly */
    printf("Person's name" GRN " [v.prop]" NC ": %s\n", bill.name);
    /* 2) Accessing the struct through pointers using the indirection operator */
    printf("Person's name" GRN " [(*ptr).prop, where Type *ptr =&v]" NC ": %s\n", (*firstGuy).name);
    /* 3) Accessing the struct through pointers using the arrow operator */
    printf("Person's name" GRN " [ptr->prop, where Type *ptr =&v]" NC ": %s\n", firstGuy->name);

    printf("Person's position: {x,y,z} : %.1f, %.1f, %.1f\n\n",
           firstGuy->pos[0],
           firstGuy->pos[1],
           firstGuy->pos[2]);

    printf("Linkedlist....\n");
    /* Walking a single linked list... */
    firstGuy->friend = malloc(sizeof(Person));
    firstGuy->friend->name = "Elon Musk";
    firstGuy->friend->active = false;

    /* Go through the list... manually?? */
    firstGuy->friend->friend = malloc(sizeof(Person));
    firstGuy->friend->friend->name = "Andrea";

    firstGuy->friend->friend->friend = NULL;
    struct Person *head = firstGuy;

    while (head->friend != NULL) {

        printf("%s's friend is : ", head->name);
        head = head->friend;
        printf("%s\n", head->name);
    }

    /* Allocating an array of Person */
    int num = 10;
    Person *manyGuys = malloc(num * sizeof(Person));

    /* Accessing the 2nd element of manyGuys using array notation */
    manyGuys[0].name = "Mario";
    manyGuys[0].friend = &bill;

    /* Accessing the 2nd element of manyGuys using pointers */
    (manyGuys + 1)->name = "Tom";
    printf("manyGuys[1].name = %s\n", manyGuys[1].name);
    free(manyGuys);
    // free(firstGuy->friend->friend->friend);
    // free(firstGuy->friend->friend);
    // free(firstGuy->friend);
    // free(firstGuy);
    free_chain(firstGuy);
    return EXIT_SUCCESS;
}
void free_chain(struct Person *p) {
    while (p != NULL) {
        struct Person *next = p->friend; //store next ref before
        free(p);                         //deleting current ref
        p = next;                        //Set next as current
    }
}