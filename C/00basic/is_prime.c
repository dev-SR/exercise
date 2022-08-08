#include <math.h>
#include <stdio.h>

int is_prime(int n) {
    int i;
    if (n == 2) {
        return 1;
    }

    if (n % 2 == 0)
        return 0;

    int upto = sqrt(n); // or n/2

    for (i = 3; i < upto; i = i + 2) { // i+=2 to avoid even number altogether
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}
int main() {
    int n;
    while (1) {

        printf("Please Enter a number (0 to exit):");
        scanf("%d", &n);
        if (n == 0)
            break;
        if (1 == is_prime(n))
            printf("%d is prime\n", n);
        else
            printf("%d is not a prime\n", n);
    }

    return 0;
}
