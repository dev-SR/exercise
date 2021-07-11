#include <stdio.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"

// we cannot use variable or constants with brace-initialization
#define LEN 5
#include <stdint.h> //for int8_t
// #include <stdlib.h>

int main() {

    printf(GRN "=== Initializing Arrays ===\n" NC);

    int a[LEN]; // a has type int[5] and contains unpredictable values!

    /* Before moving on we need a to contain all 1s */
    for (int i = 0; i < LEN; i++) {
        a[i] = 1;
    }

    /* Array initialization from brace-enclosed lists */
    int x[] = {1, 2, 3, 4, 5}; //1, 2, 3, 4, 5
    int y[LEN] = {1, 2, 3};    //1, 2, 3, 0, 0
    int z[LEN] = {0};          //0, 0, 0, 0, 0

    /* Array initialization with designators (sparse array) */
    int w[LEN] = {[1] = 1, [3] = 1};               //0, 1, 0, 1, 0
    int q[LEN] = {[1] = 3, [LEN - 1] = 5};         //0, 3, 0, 0, 5
    int t[10] = {[0] = 5, 4, [LEN - 3] = 3, 2, 1}; //5, 4, 0, 0, ..., 3, 2, 1

    printf(GRN "=== Find the size of an Array ===\n" NC);
    //%ld , sizeof operator returns the output in size_t format.
    //it is an unsigned int  format.
    int n[] = {1, 2, 3, 4, 5};
    printf("sizeof(n): %ld\n", sizeof(n));
    printf("sizeof(n[0]): %ld\n", sizeof(n[0]));
    printf("sizeof(int): %ld\n", sizeof(int));
    printf("array length: %ld\n\n", sizeof(n) / sizeof(n[0]));

    int8_t k[] = {1, 2, 3, 4, 5};
    printf("sizeof(k): %ld\n", sizeof(k));
    printf("sizeof(k[0]): %ld\n", sizeof(k[0]));
    printf("sizeof(int8_t): %ld\n", sizeof(int8_t));
    printf("array length: %ld\n", sizeof(k) / sizeof(k[0]));

    return 0;
}

// sizeof(n): 20
// sizeof(n[0]): 4
// sizeof(int): 4
// array length: 5

// sizeof(k): 5
// sizeof(k[0]): 1
// sizeof(int8_t): 1
// array length: 5
