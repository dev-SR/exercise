#include <stdio.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"

#include <stdint.h>
// #include <stdlib.h>

int main() {
    printf("=== Pointers and Arrays ===\n");

    int x[] = {9, 8, 7, 6, 5};
    int n = sizeof(x) / sizeof(x[0]);

    /* Let's recall:
     *  - an array is an ordered collection of items of the same type
     *  - a pointer holds the address of other data
     * 
     * Can we access the elements of an array through pointers? Yes!
     * 
     * */
    printf(GRN "Array address, &x[0]==x ??\n" NC);
    printf("&x[0]: %llX\n", &x[0]);
    printf("x:     %llX\n", x);

    printf(GRN "Access an element of x through the pointer:\n" NC);
    int *p = &x[2];
    printf("x[2]: %d, *p: %d\n", x[2], *p);
    *p = 0;
    printf("x[2]: %d, *p: %d\n", x[2], *p);

    // int *alias = x;
    // int *alias = &x[0];

    p = x;

    printf(GRN "Display x through the pointer:\n" NC);
    for (int i = 0; i < n; i++) {
        printf("x[%d]: %d, p[%d]: %d\n", i, x[i], i, p[i]);
    }

    printf(GRN "Set x to 0, 1, 2, 3, 4 through the pointer:\n" NC);
    for (int i = 0; i < n; i++) {
        p[i] = i;
        printf("x[%d]: %d, p[%d]: %d\n", i, x[i], i, p[i]);
    }
    return 0;
}
// === Pointers and Arrays ===
// Array address, &x[0]==x ?? :
// &x[0]: 4012E00061FEF8
// x:     4012E00061FEF8
// Access an element of x through the pointer:
// x[2]: 7, *p: 7
// x[2]: 0, *p: 0
// Display x through the pointer:
// x[0]: 9, p[0]: 9
// x[1]: 8, p[1]: 8
// x[2]: 0, p[2]: 0
// x[3]: 6, p[3]: 6
// x[4]: 5, p[4]: 5
// Set x to 0, 1, 2, 3, 4 through the pointer:
// x[0]: 0, p[0]: 0
// x[1]: 1, p[1]: 1
// x[2]: 2, p[2]: 2
// x[3]: 3, p[3]: 3
// x[4]: 4, p[4]: 4