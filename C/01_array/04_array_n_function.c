#include <stdio.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"

#define X_LEN 4

int sum_arr(int arr[], const int len) {
    printf("In sum_arr: %d\n", sizeof(arr));
    /**
     *? warning:'sizeof' on array function parameter 'arr' will return size of 'int*'
     *
     *! Inside sum_arr we only have the `address` of the array not the whole array.
     *! So, arrays are always `Pass by Reference`.

     As a result below code will give wrong answer.
     **   int n = sizeof(arr) / sizeof(int); // [8/4=2]
     **   for (int i = 0; i < n; i++) {
     **       printf("%d, ", arr[i]);
     **   }
     *!  Output: 1,4   [first two el.]
     *
     * So, to be more explict we can use pointer `int *p`, as sum_ptr() below->
     */

    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += arr[i];
    }
    return sum;
}

int sum_ptr(const int *const p, const int len) {
    printf("In sum_ptr: %d\n", sizeof(p));
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += p[i];
    }
    return sum;
}

int main() {
    printf("\n=== Array and Function ===\n\n");

    int x[X_LEN] = {1, 4, -3, 2};
    printf("In Main: %d\n", sizeof(x));

    printf(GRN "sum_arr: %d\n\n" NC, sum_arr(x, X_LEN));
    printf(GRN "sum_ptr: %d\n" NC, sum_ptr(x, X_LEN));

    return 0;
}
