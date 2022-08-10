#include <stdio.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"

#include <math.h>
#define SIZE 40

int area[SIZE];

void print_area() {
    int i;
    for (i = 2; i < SIZE; i++) {
        printf("%4d", area[i]);
    }
    printf("\n");
    for (i = 2; i < SIZE; i++) {
        printf("----");
    }
    printf("\n");
}

void sieve() {
    int i;
    for (i = 2; i < SIZE; i++) {
        area[i] = 1; // initially mark from 2 to 40 as prime [ 1 1 1 1 1 1....]
    }
    print_area();

    int upto = sqrt(SIZE);

    for (i = 2; i < upto; i++) {
        if (area[i] == 1) {                       // current number is prime
            for (int j = 2; i * j <= SIZE; j++) { // or i*j<=SIZE also possible
                // mark all it's multiple as not prime
                int multiples_of_i = i * j;
                area[multiples_of_i] = 0;
            }
            print_area();
        }
    }
}
int is_prime(int n) {
    int i;
    if (n < 2)
        return 0;
    return area[n];
}

int main() {
    int n;
    sieve();
    while (1) {
        printf("Please enter a number (0 to exit):");
        scanf("%d", &n);
        if (n == 0)
            break;

        if (n >= SIZE) {
            printf("Number should be less than %d\n", SIZE);
            continue;
        }

        if (1 == is_prime(n)) {
            printf("%d is a prime number\n", n);
        } else {
            printf("%d is not a prime number\n", n);
        }
    }

    return 0;
}
