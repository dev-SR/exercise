#include <stdio.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"
int main() {
    int a, b, temp, gcd;
    scanf("%d %d", &a, &b);

    if (a == 0) {
        gcd = a;
    } else if (b == 0) {
        gcd = b;
    } else {
        while (b != 0) {
            // gcd(a,b) = gcd(b,a%b)
            temp = b;
            b = a % b; // a<->b
            a = temp;  // b<->a%b
        }
        gcd = a;
        printf("%d", gcd);
    }

    return 0;
}
