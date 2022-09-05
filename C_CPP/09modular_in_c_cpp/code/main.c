#include "lib/circle.h"
#include <stdio.h>
int main() {
    int r = 5;
    printf("Area of circle with radius %d is %.2f\n", r, area(r));
    printf("Circumference of circle with radius %d is %.2f\n", r, circumference(r));

    return 0;
}
