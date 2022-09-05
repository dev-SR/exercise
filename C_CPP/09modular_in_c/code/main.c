#include "lib/my_header.h"
#include <stdio.h>
int main() {
    int a = 10, b = 5;
    printf("%d + %d = %d\n", a, b, add(a, b));
    printf("%d x %d = %d\n", a, b, multiply(a, b));

    return 0;
}
