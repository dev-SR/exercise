#include <stdio.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"

/**
 * if value>0 =>accumulate value in accumulator => return 0(SUCCESS)
 * else=> do nothing => return -1(FAIL)
 */
int accumulate(int *const accumulator, int value) {
    if (value > 0) {
        *accumulator += value;
        return 0;
    } else {
        return -1;
    }
}
void accumulatorWrapper(int *const accumulator, int value) {
    if (accumulate(accumulator, value)) {
        printf("Warning!! Value = %d not allowed\n", value);
    }
}

int main() {
    int accumulator = 0;
    accumulatorWrapper(&accumulator, 1);
    accumulatorWrapper(&accumulator, 0);
    accumulatorWrapper(&accumulator, -1);
    accumulatorWrapper(&accumulator, 2);
    printf("Accumulator : %d", accumulator);
    return 0;
}
// Warning!! Value = 0 not allowed
// Warning!! Value = -1 not allowed
// Accumulator : 3