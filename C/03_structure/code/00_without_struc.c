#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

double calc_distance(int dimensions, double a[dimensions], double b[dimensions]) {
    double square_distance = 0;
    for (int i = 0; i < dimensions; i++) {
        square_distance += pow(a[i] - b[i], 2);
    }
    return sqrt(square_distance);
    /* AB=√{(x2−x1)^2+(y2−y1)^2+(z2−z1)^2}*/
}

int main() {
    /* Let's calculate the distance between two guys */

    char elon_name[] = "Elon Musk";
    int elon_dimensions = 3;
    bool elon_active = true;
    double elon_pos[] = {1, 2, 3};

    char bill_name[] = "Bill Gates";
    int bill_dimensions = 3;
    bool bill_active = true;
    double bill_pos[] = {3, 2, 1};

    // if (!elon_active || !bill_active) {
    //     printf("%s isn't active now!\n", !elon_active ? elon_name : bill_name);
    //     return EXIT_FAILURE;
    // }

    if (elon_dimensions != bill_dimensions) {
        printf("%s and %s are in different dimensions!\n", elon_name, bill_name);
        return EXIT_FAILURE;
    }

    printf("The distance between %s and %s is: %.1f\n", elon_name, bill_name, calc_distance(elon_dimensions, elon_pos, bill_pos));

    return EXIT_SUCCESS;
}
