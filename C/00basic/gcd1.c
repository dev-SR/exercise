#include <stdio.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"
int main() {
    int a, b, x, gcd;
    scanf("%d %d", &a, &b); // 12 16

    if (a > b) {
        x = b;
    } else {
        x = a;
    }

    for (; x >= 1; x--) {
        if (a % x == 0 && b % x == 0) {
            gcd = x;
            printf("%d ", gcd);
            break; // Important to stop at first factor (largest)
        }
    }

    return 0;
}
