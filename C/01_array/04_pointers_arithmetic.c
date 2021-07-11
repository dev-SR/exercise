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
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += arr[i];
    }
    return sum;
}

int sum_ptr(const int *const p, const int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += p[i];
    }
    return sum;
}

int sum_ptr_arithmetic(const int *const p, const int len) {
    printf(YEL "iterating with ptr++ \n" NC);
    int sum = 0;
    const int *p_item = p;
    while (p_item < p + len) {
        // for (; ;) {
        // p_item++
        sum += *p_item;
        printf("%ld, %ld, %d\n", p_item - p, p_item, sum);
        p_item++;
    }
    return sum;
}

int main() {
    printf("\n=== Pointers Arithmetic ===\n\n");

    int x[X_LEN] = {1, 4, -3, 2};

    printf("sum_arr: %d\n", sum_arr(x, X_LEN));
    printf("sum_ptr: %d\n", sum_ptr(x, X_LEN));

    printf(GRN "ptr++\n" NC);
    int *ptr = x; // same as: int *ptr = &x[0]
    printf("%ld, %d\n", ptr, *ptr);
    ptr++; // same as: ptr = ptr + 1
    printf("%ld, %d\n", ptr, *ptr);

    printf("---\n");
    printf("sum_ptr_arithmetic: %d\n", sum_ptr_arithmetic(x, X_LEN));

    /*
     * Illegal operations:
     *    pointer + pointer
     *    pointer / pointer
     *    pointer * pointer
     *    pointer % pointer
     * 
     */

    return 0;
}
