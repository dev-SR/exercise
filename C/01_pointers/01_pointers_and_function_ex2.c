#include <stdio.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"
// function that decompose floating points
void decompose(float number, int *int_part, float *frac_part) {
    *int_part = (int)number;
    *frac_part = number - *int_part;
}

int main() {

    int int_part;
    float frac_part, input;

    printf(GRN "Enter a floating point number: " NC);
    scanf("%f", &input);

    decompose(input, &int_part, &frac_part);

    printf(YEL "Integer part of %.2f " NC "= %d\n", input, int_part);
    printf(CYN "Fractional part of %.2f " NC "= %.2f\n", input, frac_part);

    return 0;
}
// Enter a floating point number: 1.23
// Integer part of 1.23 = 1
// Fractional part of 1.23 = 0.23

// Enter a floating point number: -1.123
// Integer part of -1.12 = -1
// Fractional part of -1.12 = -0.12